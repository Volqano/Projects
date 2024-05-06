let ( let* ) xs ys = List.concat_map ys xs

(* przyjmuje specyfikacje wiersza oraz zamalowanie kratek i sprawdza czy jest poprawnie zamalowane *)
(* verify_row : int list -> bool list -> bool *)
let rec verify_row (ps : int list) (xs : bool list) : bool = 
  match ps with
  | [] -> verify_row [0] xs
  | p :: ps' -> 
    let rec iter acc xs =
      match xs with
      | []  when (acc = p) && ps' = [] -> true
      | true :: xs' when (acc < p) -> iter (acc + 1) xs' 
      | false :: xs' when (acc = p) -> verify_row ps' xs'
      | false :: xs' when (acc = 0) -> iter acc xs' 
      | _ -> false
    in iter 0 xs

(* przyjmuje specyfikacje wiersza i jego dlugosc i generuje liste wierszy spelniajacych specyfikacje *)
(* build_row : int list -> int -> bool list list *)

(* generuje wszystkie mozliwosci i filtruje poprawne za pomoca verify_row *)
let build_row (ps : int list) (n : int) : bool list list = 
  let rec create_all (n : int) : bool list list =
    if n = 0 then [[]]
    else List.concat_map (fun arr -> [true :: arr; false :: arr]) (create_all (n-1))
  in let rec filter_rows rows acc ps =
    match rows with
    | [] | [[]] -> acc
    | r :: row' -> if (verify_row ps r) = true then filter_rows row' (r :: acc) ps else filter_rows row' acc ps
  in filter_rows (create_all n) [] ps

(* przyjmuje specyfikacje wszystkich wierszy i ich dlugosci, zwraca kandydatow na rozwiazanie skonstruowanych z samych poprwnych wierszy *)
(* nalezy wykorzystac funkcje build_row *)
(* build_candidate : int list list -> int -> bool list list list *)
let rec build_candidate (pss : int list list) (n : int) : bool list list list = 
  let rec combine_lists (xss : bool list list) (yss : bool list list list) : bool list list list =
    match xss with
    | [] -> []
    | xs :: xss' -> List.map (fun x -> xs :: x) yss @ combine_lists xss' yss
  in match pss with
    | [] -> [[]]
    | [[]] -> build_candidate [[0]] n
    | ps :: pss' -> if ps = [] then combine_lists (build_row [0] n) (build_candidate pss' n) else
      combine_lists (build_row ps n) (build_candidate pss' n)

(* przyjmuje specyfikacje wszystkich wierszy i zamalowan kratek, sprawdza czy wiersze planszy spelniaja specyfikacje *)
(* nalezy wykorzystac verify_row | Po uzyciu transpose funkcja ta nadaje sie tez do sprawdzania kolumn *)
(* verify_rows : int list list -> bool list list -> bool *)
let rec verify_rows (pss : int list list) (xss : bool list list) : bool = 
  match pss, xss with
  | [], [] -> true
  | [], _ | _, [] -> false
  | (ps :: pss'), (xs :: xss') -> if (verify_row ps xs) = true then verify_rows pss' xss' else false

(* przeksztalca zadana liste list (n wierszy dlugosci m) zwraca liste m wierszy dlugosci n*)
(* troche jak transpozycja macierzy *)
(* transpose : 'a list list -> 'a list list *)
let rec transpose (xss : 'a list list) : 'a list list =
  match xss with
  | [] -> []
  | [] :: xs -> []
  | xs ->  (List.map List.hd xs) :: (transpose (List.map List.tl xs))

(*  Specyfikacja obrazku *)
type nonogram_spec = {rows: int list list; cols: int list list}

let solve_nonogram (nono : nonogram_spec) =
  let len = List.length (nono.cols) in
  build_candidate (nono.rows) (if len = 0 then 1 else len)
  |> List.filter (fun xss -> transpose xss |> verify_rows nono.cols)

let example_1 = {
  rows = [[2];[1];[1]];
  cols = [[1;1];[2]]
}

let example_2 = {
  rows = [[2];[2;1];[1;1];[2]];
  cols = [[2];[2;1];[1;1];[2]]
}
