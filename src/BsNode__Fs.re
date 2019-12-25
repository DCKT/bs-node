open BsNode__Types;

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

[@bs.module "fs"]
external readdir: (string, callback(array(string))) => unit = "readdir";

[@bs.module "fs"]
external readFile: (string, callback(string)) => unit = "readFile";

[@bs.module "fs"] external stat: (string, callback(Stat.t)) => unit = "stat";

[@bs.module "fs"]
external unlink: (string, Js.Nullable.t(Js.Exn.t) => unit) => unit = "unlink";

[@bs.module "fs"]
external lstat: (string, callback(LStat.t)) => unit = "lstat";