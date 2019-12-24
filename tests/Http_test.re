open BsNode_Http;
open Belt;

let server =
  Http.createServer((req, res) => {
    let url = req->Http.Request.url |> Js.String.split("?");
    let path = url->Array.getExn(0);

    switch (path) {
    | "/" => res->Http.Response.endString("Index")
    | "/hello" => res->Http.Response.endString("Hello")
    | _ => res->Http.Response.endString("any")
    };
  });

server->Http.listen(1337, () => Js.log("Server started"));