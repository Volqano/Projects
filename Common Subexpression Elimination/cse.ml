(* abstract syntax tree *)

type bop = Mult | Div | Add | Sub | Eq | Lt | Gt | Leq | Geq | Neq

type ident = string

type expr =
  | Int of int
  | Bool of bool
  | Binop of bop * expr * expr
  | If of expr * expr * expr
  | Var of ident
  | Let of ident * expr * expr

(* CSE *)

module M = Map.Make(String)
type env = ident M.t

(* funkcja alpha_equiv z listy 8 sprawdza czy wyrazenia e1 i e2 sa a' rownowazne *)
let rec alpha_equiv (e1 : expr) (e2 : expr) : bool =
  let rec helper e1 e2 env1 env2 =
    match e1, e2 with
    | Var x1, Var x2 ->
      (match M.find_opt x1 env1, M.find_opt x2 env2 with
      | Some y1, Some y2 -> y1 = x2 && y2 = x1
      | None, None -> true
      | _, _ -> false)
    | Let (x1, e1l, e1r), Let (x2, e2l, e2r) ->
      alpha_equiv e1l e2l && helper e1r e2r (M.add x1 x2 env1) (M.add x2 x1 env2)
    | Binop (op1, e1l, e1r), Binop (op2, e2l, e2r) -> if op1 != op2 then false else
        helper e1l e2l env1 env2 && helper e1r e2r env1 env2
    | If (p1, t1, e1), If (p2, t2, e2) -> p1 = p2 && t1 = t2 && e1 = e2
    | Int a, Int b -> a = b
    | Bool a, Bool b -> a = b
    | _, _ -> false
  in helper e1 e2 M.empty M.empty

(* Sprawdza czy wyrazenie e zawiera zmienna x *)  
  let rec contains_var (x : string) (e : expr) : bool = 
    match e with
    | Int _ | Bool _ -> false
    | Var y -> x = y
    | Binop (op, el, er) -> (contains_var x el) || (contains_var x er)
    | If (p, t, el) -> contains_var x p || contains_var x t || contains_var x el
    | Let (y, e1, e2) -> x = y || contains_var x e1 || contains_var x e2 

(* sprawdza czy wyrazenie e zawiera jakakolwiek zmienna z vars*)
let rec check_all_vars (vars : string list) (e : expr) : bool =
  match vars with 
  | x :: vars' -> if contains_var x e then true else check_all_vars vars' e
  | _ -> false

(* podstawia zmienna za wyrazenia alfarownowazne ktorych zmienne wolne sa wolne w calym wyrazeniu *)
let rec substitute (e : expr) (se : expr) (vars : string list) : expr = 
  if alpha_equiv e se && not (check_all_vars vars se) then Var "v1" else
  match e with
  | Binop (op, el, er) -> Binop (op, substitute el se vars, substitute er se vars)
  | If (p, t, el) -> If (substitute p se vars, substitute t se vars, substitute el se vars)
  | Let (x, e1, e2) -> Let (x, substitute e1 se (x :: vars), substitute e2 se (x :: vars))
  | _ -> e

(* tworzy tablice wszystkich mozliwych podwyrazen *)
let rec all_subexpressions (e : expr) : expr list =
  let add_expression (e : expr) (vars : string list) : expr list = 
    match e with
    | Int _ | Bool _ | Var _ -> []
    | _ -> if check_all_vars vars e then [] else [e]
  in 
  let rec helper (se : expr list) (e : expr) (vars : string list) : expr list =
    match e with
    | Int _ | Bool _ | Var _ -> []
    | Binop (_, el, er) -> se @ add_expression el vars @ add_expression er vars @ helper se el vars @ helper se er vars 
    | If (p, t, e) -> se @ add_expression p vars @ add_expression t vars @ add_expression e vars @ helper se p vars @ helper se t vars @ helper se e vars
    | Let (x, el, er) -> let vars' = (x :: vars) in 
      se @ add_expression el vars' @ add_expression er vars' @ helper se el vars' @ helper se er vars'
  in helper [] e [] 

let cse (e : expr) : expr option =
  let all = all_subexpressions e in
  let rec find_matching (exprs : expr list) (exp : expr) : expr option =
    match exprs with 
    | [] -> None
    | e1 :: e' -> 
      if alpha_equiv e1 exp then 
        Some (Let("v1", e1, (substitute e e1 []))) 
      else find_matching e' exp
  in 
  let rec find_cse (exprs : expr list) : expr option =
    match exprs with
    | [] -> None
    | e1 :: e' -> 
      match find_matching e' e1 with
      | Some exp -> Some exp
      | None -> find_cse e'
  in find_cse all


let e1 =
  Binop(Add, 
    Binop (Mult, Int 2, Var "x"),
    Binop (Add, Int 1, Binop (Mult, Int 2, Var "x")))

let e2 =
  Binop (Add,
    Binop (Mult, Var "x", Int 10),
    Let ("x", Int 3,
          Binop (Mult, Var "x", Int 10)))
    