open BsNode;

Fs.readdir("./", (err, files) =>
  switch (err->Js.Nullable.toOption) {
  | None => Js.log(files)
  | Some(e) => Js.log(e)
  }
);