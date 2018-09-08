Nghttp2 server demo
=====================

# How to build

please install just first: brew install just, then execute:

```
just setup
just build
```

# client test

After start the server, please use following code to test: 

```
$ nghttp http://localhost:3000/
$ curl --http2 --http2-prior-knowledge http://localhost:3000/
```


# References

* https://github.com/nghttp2/nghttp2