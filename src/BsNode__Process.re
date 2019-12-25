[@bs.module "process"] external cwd: unit => string = "cwd";
[@bs.module "process"] external argv: unit => array(string) = "arvs";
[@bs.module "process"]
external on:
  (
  [@bs.string]
  [
    | `beforeExit(int => unit)
    | `exit(int => unit)
    | `message(('a, 'todo) => unit)
    | `rejectionHandled('promise => unit)
  ]
  ) =>
  unit =
  "on";