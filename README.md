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
