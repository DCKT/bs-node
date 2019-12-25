[@bs.deriving jsConverter]
type cpuArch = [
  | `arm
  | `arm64
  | `ia32
  | `mips
  | `mipsel
  | `ppc
  | `ppc64
  | `s390
  | `s390x
  | `x32
  | `x64
];

[@bs.deriving jsConverter]
type platform = [
  | `aix
  | `darwin
  | `freebsd
  | `linux
  | `openbsd
  | `sunos
  | `win32
];

[@bs.module "os"] external eol: string = "EOL";
[@bs.module "os"] external homedir: unit => string = "homedir";
[@bs.module "os"] external hostname: unit => string = "hostname";
[@bs.module "os"] external release: unit => string = "release";
[@bs.module "os"] external tmpdir: unit => string = "tmpdir";
[@bs.module "os"] external type_: unit => string = "type";
[@bs.module "os"] external totalmem: unit => int = "totalmem";
[@bs.module "os"] external uptime: unit => int = "uptime";
[@bs.module "os"] external loadavg: unit => array(int) = "loadavg";
[@bs.module "os"] external _arch: unit => string = "arch";
[@bs.module "os"] external _platform: unit => string = "platform";
let arch = () => _arch()->cpuArchFromJs;
let platform = () => _platform()->platformFromJs;

module Constants = {
  module Priority = {
    [@bs.module "os"] [@bs.scope ("constants", "priority")]
    external low: string = "PRIORITY_LOW";
    [@bs.module "os"] [@bs.scope ("constants", "priority")]
    external belowNormal: string = "PRIORITY_BELOW_NORMAL";
    [@bs.module "os"] [@bs.scope ("constants", "priority")]
    external normal: string = "PRIORITY_NORMAL";
    [@bs.module "os"] [@bs.scope ("constants", "priority")]
    external aboveNormal: string = "PRIORITY_ABOVE_NORMAL";
    [@bs.module "os"] [@bs.scope ("constants", "priority")]
    external high: string = "PRIORITY_HIGH";
    [@bs.module "os"] [@bs.scope ("constants", "priority")]
    external highest: string = "PRIORITY_HIGHEST";
  };
  module Dlopen = {
    [@bs.module "os"] [@bs.scope ("constants", "dlopen")]
    external lazy_: string = "RTLD_LAZY";
    [@bs.module "os"] [@bs.scope ("constants", "dlopen")]
    external now: string = "RTLD_NOW";
    [@bs.module "os"] [@bs.scope ("constants", "dlopen")]
    external global: string = "RTLD_GLOBAL";
    [@bs.module "os"] [@bs.scope ("constants", "dlopen")]
    external local: string = "RTLD_LOCAL";
    [@bs.module "os"] [@bs.scope ("constants", "dlopen")]
    external deepbind: string = "RTLD_DEEPBIND";
  };
  module Errors = {
    [@bs.module "os"] [@bs.scope ("constants", "errno")]
    external e2big: string = "E2BIG";
    [@bs.module "os"] [@bs.scope ("constants", "errno")]
    external eacces: string = "EACCES";
    [@bs.module "os"] [@bs.scope ("constants", "errno")]
    external eaddrinuse: string = "EADDRINUSE";
    [@bs.module "os"] [@bs.scope ("constants", "errno")]
    external eaddrnotavail: string = "EADDRNOTAVAIL";
  };
  module Signals = {
    [@bs.module "os"] [@bs.scope ("constants", "signals")]
    external sighup: string = "SIGHUP";
    [@bs.module "os"] [@bs.scope ("constants", "signals")]
    external sigint: string = "SIGINT";
    [@bs.module "os"] [@bs.scope ("constants", "signals")]
    external sigquit: string = "SIGQUIT";
    [@bs.module "os"] [@bs.scope ("constants", "signals")]
    external sigill: string = "SIGILL";
    [@bs.module "os"] [@bs.scope ("constants", "signals")]
    external sigtrap: string = "SIGTRAP";
    [@bs.module "os"] [@bs.scope ("constants", "signals")]
    external sigabrt: string = "SIGABRT";
  };
};