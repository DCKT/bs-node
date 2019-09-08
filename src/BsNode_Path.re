module Path = {
  [@bs.deriving abstract]
  type formatedPath = {
    root: string,
    dir: string,
    base: string,
    name: string,
    ext: string,
  };

  [@bs.module "path"] [@bs.variadic]
  external join: array(string) => string = "join";

  [@bs.module "path"] external delimiter: string = "delimiter";
  [@bs.module "path"] external sep: string = "sep";

  [@bs.module "path"] external dirname: string => string = "dirname";

  [@bs.module "path"] external extname: string => string = "extname";

  [@bs.module "path"] external normalize: string => string = "normalize";

  [@bs.module "path"] external isAbsolute: string => bool = "isAbsolute";

  [@bs.module "path"] external parse: string => formatedPath = "parse";

  [@bs.module "path"]
  external relative: (string, string) => string = "relative";

  [@bs.module "path"] [@bs.variadic]
  external resolve: array(string) => string = "resolve";
};