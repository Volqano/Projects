## COMMON SUBEXPRESSION ELIMINATION

Common Subexpression Elimination (CSE) made in OCaml.
CSE is an optimization technique used by compilers to identify and eliminate duplicate subexpressions within a program.
When a program contains identical subexpressions, CSE replaces them with a single variable.

## Simple example

Giving input:

```bash
cse (Binop(Add, Binop (Mult, Int 2, Var "x"), Binop (Add, Int 1, Binop (Mult, Int 2, Var "x"))));;
```

Gives output:

```bash
Some (Let ("v1", Binop (Mult, Int 2, Var "x"), Binop (Add, Var "v1", Binop (Add, Int 1, Var "v1"))))
```
