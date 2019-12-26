open BsNode__Types;

let dirname = [%raw "__dirname"];

module Stream = {
  type t;

  [@bs.module "fs"]
  external createReadStream: string => t = "createReadStream";
  [@bs.module "fs"]
  external createWriteStream: string => t = "createWriteStream";

  [@bs.send.pipe: t] external pipe: t => t = "pipe";
  [@bs.send.pipe: t] external on: (string, unit => unit) => t = "on";
};

module Stat = {
  type t;

  [@bs.get] external size: t => float = "size";
};

module LStat = {
  type t;

  [@bs.send] external isDirectory: (t, unit) => bool = "isDirectory";
  [@bs.send] external isFile: (t, unit) => bool = "isFile";
};

module Dirent = {
  type t;

  [@bs.send] external isDirectory: t => bool = "isDirectory";
  [@bs.send] external isFile: t => bool = "isFile";
  [@bs.get] external nameAsString: t => string = "name";
  [@bs.get] external nameAsBuffer: t => Buffer.t = "name";
};

[@bs.module "fs"]
external readdir: (string, callback(array(string))) => unit = "readdir";

type readdirOptions;

[@bs.obj]
external readdirOptions:
  (
    ~encoding: [@bs.string] [ | `utf8 | `ascii]=?,
    ~withFileTypes: bool=?,
    unit
  ) =>
  readdirOptions =
  "";

[@bs.module "fs"]
external readdirWithOptions:
  (string, readdirOptions, callback(array(string))) => unit =
  "readdir";

[@bs.module "fs"]
external readdirWithFileTypes:
  (string, readdirOptions, callback(array(Dirent.t))) => unit =
  "readdir";

[@bs.module "fs"]
external readFile: (string, callback(string)) => unit = "readFile";

type readFileOptions;

[@bs.obj]
external readFileOptions:
  (
    ~encoding: [@bs.string] [ | `utf8 | `ascii]=?,
    ~flag: [@bs.string] [ | `_r | `_ax | `_a | `_as | `_w | `_wx]=?,
    unit
  ) =>
  readdirOptions =
  "";

[@bs.module "fs"]
external readFileWithOptions:
  (string, readFileOptions, callback(string)) => unit =
  "readFile";

[@bs.module "fs"] external stat: (string, callback(Stat.t)) => unit = "stat";

[@bs.module "fs"]
external unlink: (string, Js.Nullable.t(Js.Exn.t) => unit) => unit = "unlink";

[@bs.module "fs"]
external lstat: (string, callback(LStat.t)) => unit = "lstat";