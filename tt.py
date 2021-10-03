#!/usr/bin/env python3
"""Testing benchmark functions with different data types.
"""
import optobench as ob
import numpy as np


print('# Testing LIST')
xs = [0.1, 0.2, 0.3, 0.4, 0.51, .63]
for el in dir(ob):
    if el.startswith("_"):
        continue
    print(f"-> {el}: ", end="", flush=True)
    fn = getattr(ob, el)

    ans = None
    try:
        ans = fn(xs)
    except Exception as e:
        ans = str(e)
    print(ans)
print()


print('## Testing 1D numpy array..')
xs = np.array([0.1, 0.2, 0.3, 0.4, 0.51, .63])
for el in dir(ob):
    if el.startswith("_"):
        continue
    print(f"-> {el}: ", end="", flush=True)
    fn = getattr(ob, el)

    ans = None
    try:
        ans = fn(xs)
    except Exception as e:
        ans = str(e)
    print(ans)
print()


print('## Testing 2D numpy array')
xs = [[0.4  , 0.31 , 0.445, 0.218, 0.581, 0.171, 0.532, 0.24 ],
      [0.265, 0.43 , 0.568, 0.144, 0.4  , 0.333, 0.188, 0.402],
      [0.191, 0.366, 0.234, 0.272, 0.307, 0.436, 0.203, 0.361],
      [0.262, 0.254, 0.407, 0.254, 0.254, 0.335, 0.169, 0.265],
      [0.362, 0.097, 0.167, 0.269, 0.395, 0.659, 0.234, 0.127],
      [0.123, 0.243, 0.568, 0.117, 0.287, 0.361, 0.214, 0.435],
      [0.505, 0.15 , 0.405, 0.36 , 0.281, 0.214, 0.498, 0.156],
      [0.235, 0.39 , 0.353, 0.487, 0.196, 0.451, 0.362, 0.34 ],
      [0.148, 0.382, 0.237, 0.789, 0.185, 0.182, 0.392, 0.081],
      [0.225, 0.309, 0.316, 0.118, 0.48 , 0.562, 0.309, 0.028],
      [0.686, 0.667, 0.166, 0.367, 0.659, 0.252, 0.422, 0.186],
      [0.407, 0.256, 0.307, 0.413, 0.352, 0.487, 0.376, 0.112],
      [0.394, 0.411, 0.463, 0.434, 0.405, 0.24 , 0.241, 0.243],
      [0.45 , 0.345, 0.452, 0.272, 0.349, 0.281, 0.664, 0.672],
      [0.097, 0.222, 0.173, 0.085, 0.524, 0.507, 0.48 , 0.371],
      [0.391, 0.567, 0.343, 0.191, 0.476, 0.394, 0.122, 0.277],
      [0.283, 0.559, 0.277, 0.203, 0.503, 0.225, 0.1  , 0.396],
      [0.359, 0.341, 0.398, 0.438, 0.374, 0.256, 0.183, 0.105],
      [0.428, 0.297, 0.225, 0.12 , 0.275, 0.413, 0.378, 0.193],
      [0.27 , 0.195, 0.121, 0.601, 0.231, 0.515, 0.269, 0.417],
      [0.433, 0.346, 0.407, 0.416, 0.469, 0.129, 0.202, 0.696],
      [0.093, 0.228, 0.339, 0.377, 0.511, 0.382, 0.523, 0.23 ],
      [0.064, 0.482, 0.273, 0.186, 0.578, 0.201, 0.241, 0.339],
      [0.341, 0.255, 0.448, 0.186, 0.496, 0.62 , 0.36 , 0.369]]
xs = np.array(xs)
for el in dir(ob):
    if el.startswith("_"):
        continue
    print(f"-> {el}: ", end="", flush=True)
    fn = getattr(ob, el)

    ans = None
    try:
        ans = fn(xs)
    except Exception as e:
        ans = str(e)
    print(ans)
print()