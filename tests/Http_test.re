open BsNode;
open Belt;

let htmlFile: ref(option(string)) = ref(None);

Fs.readFile("./index.html", (err, data) =>
  switch (err->Js.Nullable.toOption) {
  | Some(err) => Js.log2("Unable to read\n", err)
  | None => htmlFile := Some(data)
  }
);

let server =
  Http.createServer((req, res) => {
    let url = req->Http.Request.url |> Js.String.split("?");
    let path = url->Array.getExn(0);

    switch (path) {
    | "/" => res->Http.Response.endString("Index")
    | "/hello" => res->Http.Response.endString("Hello")
    | "/html" =>
      res->Http.Response.endString(
        (htmlFile^)->Option.mapWithDefault("no file", r => r),
      )
    | _ => res->Http.Response.endString("any")
    };
  });

server->Http.listen(1337, () => Js.log("Server started"));