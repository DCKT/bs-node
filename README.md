# bs-node 🚧

Bucklescript bindings for Node.js

## Install

```
yarn add @dck/bs-node
```

Add it to `bs-dependencies` in your `bsconfig.json` :

```json
{
  "bs-dependencies": ["@dck/bs-node"]
}
```

## Usage

### Fs

```reason
open BsNode;

Fs.readdir("./somepath/folder", (err, files) => {
  switch (err->Js.Nullable.toOption) {
    | None => Js.log(files)
    | Some(e) => Js.log(e)
  }
});
```

### http

```reason
open BsNode;
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
```
