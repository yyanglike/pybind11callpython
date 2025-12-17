"""
动态函数测试模块 - 用于测试C++动态调用Python函数
"""

def func_no_args():
    """无参数函数"""
    return "no_args"

def func_one_arg(x):
    """一个参数函数"""
    return f"one_arg: {x}"

def func_two_args(x, y):
    """两个参数函数"""
    return f"two_args: {x}, {y}"

def func_default_args(x=10, y=20):
    """带默认参数的函数"""
    return f"default_args: {x}, {y}"

def func_var_args(*args):
    """可变位置参数函数"""
    return f"var_args: {args}"

def func_kwargs(**kwargs):
    """可变关键字参数函数"""
    return f"kwargs: {kwargs}"

def func_mixed(x, y=5, *args, **kwargs):
    """混合参数函数"""
    return f"mixed: x={x}, y={y}, args={args}, kwargs={kwargs}"

# 测试函数
if __name__ == "__main__":
    print(func_no_args())
    print(func_one_arg(100))
    print(func_two_args(1, 2))
    print(func_default_args())
    print(func_default_args(30, 40))
    print(func_var_args(1, 2, 3))
    print(func_kwargs(a=1, b=2))
    print(func_mixed(10, 20, 30, 40, extra=50))
