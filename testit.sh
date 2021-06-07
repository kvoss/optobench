python -c 'import cbench as cb

xs = [0.1, 0.2, 0.3, 0.4, 0.51]
for el in dir(cb):
    if el.startswith("_"):
        continue
    print(f"-> {el}: ", end="", flush=True)
    fn = getattr(cb, el)
    ans = fn(xs)
    print(ans)

'
