#!/bin/sh

echo "=> Running sanity tests.."
python3 -c 'import optobench as ob

xs = [0.1, 0.2, 0.3, 0.4, 0.51]
for el in dir(ob):
    if el.startswith("_"):
        continue
    print(f"-> {el}: ", end="", flush=True)
    fn = getattr(ob, el)
    if el == "hartmann_6d":
        ans = fn([0.1, 0.2, 0.3, 0.4, 0.51, 0.63])
    else:
        ans = fn(xs)
    print(ans)

' > sanity-test-instance.log

echo "=> Differences:"
diff -u sanity-test-golden.log sanity-test-instance.log

# echo "Timing test.."
# python -m timeit -s 'from obench import michalewicz; xs = [0.1, 0.2, 0.3, 0.4, 0.51]' 'michalewicz(xs)'
echo "=> Done."
