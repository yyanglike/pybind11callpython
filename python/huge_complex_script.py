#!/usr/bin/env python3
"""
huge_complex_script.py
A deliberately complex, self-contained script that exercises many Python features
- argparse, logging, decorators, context managers, classes, generators
- nested functions, closures, *args/**kwargs, dict merging, comprehensions
- exception handling, file I/O, and simple metaprogramming

This script is safe to run and prints a structured summary of actions it performed.
"""

import argparse
import sys
import json
import math
import logging
from contextlib import contextmanager
from functools import wraps
from typing import Any, Dict, Iterable

# ---- Logging setup ----
logger = logging.getLogger('huge_script')
logger.setLevel(logging.DEBUG)
ch = logging.StreamHandler()
ch.setLevel(logging.DEBUG)
formatter = logging.Formatter('[%(levelname)s] %(message)s')
ch.setFormatter(formatter)
logger.addHandler(ch)

# ---- Utilities ----
@contextmanager
def temp_resource(name: str):
    logger.debug(f"allocating resource: {name}")
    try:
        yield {'name': name}
    finally:
        logger.debug(f"releasing resource: {name}")


def make_multiplier(factor: int):
    def multiplier(x):
        return x * factor
    return multiplier


def timed(fn):
    @wraps(fn)
    def wrapper(*args, **kwargs):
        logger.debug(f"Entering {fn.__name__}")
        result = fn(*args, **kwargs)
        logger.debug(f"Exiting {fn.__name__}")
        return result
    return wrapper

# ---- Complex data transforms ----
@timed
def combine_and_transform(*iterables: Iterable[int], multipliers: Dict[str, int] = None, **kw):
    """Merges iterables, applies multipliers and returns a dict summary."""
    multipliers = multipliers or {}
    merged = []
    for it in iterables:
        merged.extend(list(it))
    # apply a chain of operations using *args and **kwargs
    factors = [v for v in multipliers.values()] or [1]
    total_product = 1
    for f in factors:
        total_product *= f
    processed = [ (x ** 2) * total_product for x in merged ]
    summary = {
        'count': len(processed),
        'sum': sum(processed),
        'max': max(processed) if processed else None,
        'min': min(processed) if processed else None,
        'factors': factors
    }
    return processed, summary

# ---- Generator/iterator examples ----
def sliding_window(seq, n=2):
    it = iter(seq)
    window = []
    for _ in range(n):
        try:
            window.append(next(it))
        except StopIteration:
            return
    yield tuple(window)
    for elem in it:
        window = window[1:] + [elem]
        yield tuple(window)

# ---- Metaprogramming ----
class Descriptor:
    def __init__(self, name):
        self.name = name
    def __get__(self, obj, objtype=None):
        return f"Descriptor({self.name})"

class DynamicClass:
    a = Descriptor('a')
    def __init__(self, **kwargs):
        self.__dict__.update(kwargs)
    def __repr__(self):
        return f"DynamicClass({self.__dict__})"

# ---- Complex callable with **kwargs merging ----
def complex_callable(required, /, *args, flag=False, **kwargs):
    d1 = {'alpha': 1, 'beta': 2}
    d2 = {**d1, **kwargs}  # dict merge, kwargs can override
    return {
        'required': required,
        'args': list(args),
        'flag': flag,
        'merged': d2
    }

# ---- Decorated function using closure and nested defs----
def make_power_closure(exp):
    def pow_fn(x):
        # right-associative demonstration: x ** (exp ** 1) => same as x ** exp
        return x ** exp
    return pow_fn

# ---- File IO and exception handling ----
@timed
def persist_summary(summary: Dict[str, Any], filename: str):
    try:
        with open(filename, 'w', encoding='utf-8') as f:
            json.dump(summary, f, indent=2)
        return True
    except Exception as e:
        logger.error(f"Failed to persist summary: {e}")
        return False

# ---- Main flow ----

def main(argv=None):
    argv = argv if argv is not None else sys.argv[1:]
    parser = argparse.ArgumentParser(description='Huge Complex Script')
    parser.add_argument('--nums', '-n', nargs='*', type=int, default=[1,2,3,4], help='numbers to process')
    parser.add_argument('--more', '-m', nargs='*', type=int, default=[], help='additional numbers')
    parser.add_argument('--factor', type=int, default=2, help='multiplier factor')
    parser.add_argument('--out', type=str, default='huge_summary.json', help='output file')
    parser.add_argument('--flag', action='store_true', help='a boolean flag')
    args = parser.parse_args(argv)

    logger.info('Starting complex operations')

    with temp_resource('main-temp') as res:
        m = make_multiplier(args.factor)
        processed, summary = combine_and_transform(args.nums, args.more, multipliers={'f': args.factor})
        # apply multiplier to first element if exists
        if processed:
            processed = [ m(x) for x in processed ]
        # use sliding window generator
        windows = list(sliding_window(processed, n=3))
        # dynamic class usage
        dyn = DynamicClass(runtime_sum=summary['sum'], windows=windows)
        # complex callable
        c = complex_callable('REQ', *processed[:2], flag=args.flag, gamma=9)
        # power closure demonstration
        pow3 = make_power_closure(3)
        pow_result = pow3(2)  # 2 ** 3 = 8

        final = {
            'original_args': vars(args),
            'processed_len': len(processed),
            'processed_sample': processed[:5],
            'sliding_windows': windows,
            'dynamic_repr': repr(dyn),
            'callable_result': c,
            'pow': pow_result,
            'resource': res,
        }

        saved = persist_summary(final, args.out)

    logger.info('Completed complex operations')
    # Print JSON to stdout for easy capture
    print(json.dumps({'final': final, 'saved': saved}, default=str, indent=2))


if __name__ == '__main__':
    main()
