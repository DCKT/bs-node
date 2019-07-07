module Fs = {
  type callbackError = Js.Nullable.t(Js.Exn.t) => unit;

  module Stream = {
    type t;

    [@bs.module "fs"]
    external createReadStream: string => t = "createReadStream";
    [@bs.module "fs"]
    external createWriteStream: string => t = "createWriteStream";

    [@bs.send.pipe: t] external pipe: t => t = "pipe";
    [@bs.send.pipe: t] external on: (string, unit => unit) => t = "on";
  };

  type stream;
  type stats;

  [@bs.get] external size: stats => float = "size";

  [@bs.module "fs"]
  external readdir:
    (string, (Js.Nullable.t(Js.Exn.t), array(string)) => unit) => unit =
    "readdir";

  [@bs.module "fs"]
  external stat: (string, (Js.Nullable.t(Js.Exn.t), stats) => unit) => unit =
    "stat";

  [@bs.module "fs"]
  external unlink: (string, callbackError) => unit = "unlink";
};

module Path = {
  [@bs.module "path"] [@bs.variadic]
  external join: array(string) => string = "join";
};