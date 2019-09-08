module Http = {
  type server;

  module Request = {
    type t;
  };

  module Response = {
    type t;
    type end_;

    [@bs.send] external endUnit: (t, unit) => end_ = "end";
    [@bs.send] external endString: (t, string) => end_ = "end";
    [@bs.send] external writeHead: (t, int, Js.t('a)) => unit = "end";
    [@bs.send]
    external writeHeadsetHeader: (t, string, string) => unit = "end";
  };

  [@bs.module "http"]
  external createServer: ((Request.t, Response.t) => Response.end_) => server =
    "createServer";
};