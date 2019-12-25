type server;

module Request = {
  type t;

  [@bs.get] external url: t => string = "url";
  [@bs.get] external path: t => string = "path";
  [@bs.get] external rawHeaders: t => array(string) = "path";
  [@bs.get] external getHeader: t => option(string) = "getHeader";
  [@bs.send] external setHeader: (t, string, string) => unit = "setHeader";
  [@bs.send] external removeHeader: (t, string) => unit = "removeHeader";
};

module Response = {
  type t;
  type end_;

  [@bs.send] external endUnit: (t, unit) => end_ = "end";
  [@bs.send] external endString: (t, string) => end_ = "end";
  [@bs.send] external writeHead: (t, int, Js.t('a)) => unit = "end";
  [@bs.send] external writeHeadsetHeader: (t, string, string) => unit = "end";
};

[@bs.module "http"]
external createServer: ((Request.t, Response.t) => Response.end_) => server =
  "createServer";

[@bs.send] external listen: (server, int, unit => unit) => unit = "listen";