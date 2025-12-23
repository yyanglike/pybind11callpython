"""
复杂测试脚本 - 用于发现脚本解释器的潜在bug
包含多种边缘情况和复杂交互
"""

# 复杂的数据结构类
class ComplexData:
    def __init__(self, name, data=None):
        self.name = name
        self.data = data if data is not None else {}
        self.history = []
    
    def add_record(self, key, value):
        """添加记录到数据中"""
        self.data[key] = value
        self.history.append(f"add:{key}:{value}")
        return len(self.history)
    
    def get_record(self, key, default=None):
        """获取记录"""
        return self.data.get(key, default)
    
    def process_data(self, processor_func):
        """使用处理器函数处理数据"""
        results = {}
        for key, value in self.data.items():
            try:
                results[key] = processor_func(value)
            except Exception as e:
                results[key] = f"Error: {e}"
        return results
    
    @classmethod
    def create_from_dict(cls, name, data_dict):
        """从字典创建实例"""
        instance = cls(name)
        instance.data.update(data_dict)
        return instance
    
    @staticmethod
    def merge_instances(*instances):
        """合并多个实例"""
        if not instances:
            return None
        
        merged = ComplexData("merged")
        for instance in instances:
            merged.data.update(instance.data)
            merged.history.extend(instance.history)
        
        return merged

    # Compatibility wrapper expected by tests
    def process_complex(self, config):
        """Compatibility wrapper: apply simple transformations described by config and return result."""
        try:
            input_data = config.get("input_data", []) if isinstance(config, dict) else []
            result = list(input_data)
            for t in config.get("transformations", []) if isinstance(config, dict) else []:
                if t.get("type") == "scale" and "factor" in t:
                    result = [x * t["factor"] for x in result]
                if t.get("type") == "offset" and "value" in t:
                    result = [x + t["value"] for x in result]
            return {"processed": result}
        except Exception as e:
            return {"error": str(e)}

# 数学计算类
class MathOperations:
    def __init__(self, base_value=0):
        self.base = base_value
        self.cache = {}
    
    def calculate(self, operation, *args):
        """执行数学计算"""
        cache_key = f"{operation}:{args}"
        
        if cache_key in self.cache:
            return self.cache[cache_key]
        
        try:
            if operation == "add":
                result = sum(args) + self.base
            elif operation == "multiply":
                result = 1
                for arg in args:
                    result *= arg
                result += self.base
            elif operation == "power":
                if len(args) >= 2:
                    result = args[0] ** args[1] + self.base
                else:
                    result = None
            elif operation == "complex":
                # 复杂计算：sin(x) + cos(y) * z
                import math
                if len(args) >= 3:
                    x, y, z = args[0], args[1], args[2]
                    result = math.sin(x) + math.cos(y) * z + self.base
                else:
                    result = None
            else:
                result = None
            
            if result is not None:
                self.cache[cache_key] = result
            
            return result
            
        except Exception as e:
            return f"Calculation error: {e}"
    
    def clear_cache(self):
        """清空缓存"""
        self.cache.clear()
        return len(self.cache)

# 递归数据结构
class TreeNode:
    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []
    
    def add_child(self, child_node):
        """添加子节点"""
        self.children.append(child_node)
        return len(self.children)
    
    def traverse(self, visitor_func, depth=0):
        """遍历树节点"""
        results = [visitor_func(self.value, depth)]
        for child in self.children:
            results.extend(child.traverse(visitor_func, depth + 1))
        return results
    
    def find_nodes(self, condition_func):
        """查找满足条件的节点"""
        nodes = []
        if condition_func(self.value):
            nodes.append(self)
        
        for child in self.children:
            nodes.extend(child.find_nodes(condition_func))
        
        return nodes
    
    @property
    def is_leaf(self):
        """是否为叶子节点"""
        return len(self.children) == 0
    
    @property
    def depth(self):
        """计算树的深度"""
        if not self.children:
            return 1
        return 1 + max(child.depth for child in self.children)

# 异常测试类
class ErrorGenerator:
    def __init__(self):
        self.error_count = 0
    
    def generate_error(self, error_type="default"):
        """生成不同类型的错误"""
        self.error_count += 1
        
        if error_type == "division_by_zero":
            return 1 / 0
        elif error_type == "index_error":
            lst = [1, 2, 3]
            return lst[10]
        elif error_type == "key_error":
            dct = {"a": 1, "b": 2}
            return dct["c"]
        elif error_type == "attribute_error":
            obj = object()
            return obj.nonexistent_method()
        elif error_type == "type_error":
            return "string" + 123
        elif error_type == "recursion":
            return self.generate_error("recursion")  # 无限递归
        else:
            raise ValueError(f"Unknown error type: {error_type}")
    
    def safe_execute(self, func, *args, **kwargs):
        """安全执行函数，捕获异常"""
        try:
            return func(*args, **kwargs)
        except Exception as e:
            return f"Caught exception: {type(e).__name__}: {e}"
    
    def get_error_stats(self):
        """获取错误统计"""
        return {
            "error_count": self.error_count,
            "status": "active" if self.error_count > 0 else "inactive"
        }

# 性能测试函数
def performance_test(iterations=1000):
    """性能测试函数"""
    import time
    
    results = {
        "iterations": iterations,
        "operations": []
    }
    
    # 测试1: 列表操作
    start = time.time()
    test_list = []
    for i in range(iterations):
        test_list.append(i * i)
    list_time = time.time() - start
    results["operations"].append(("list_append", list_time, len(test_list)))
    
    # 测试2: 字典操作
    start = time.time()
    test_dict = {}
    for i in range(iterations):
        test_dict[f"key_{i}"] = i ** 0.5
    dict_time = time.time() - start
    results["operations"].append(("dict_insert", dict_time, len(test_dict)))
    
    # 测试3: 数学计算
    start = time.time()
    total = 0
    for i in range(iterations):
        total += i * 3.14159 / (i + 1)
    math_time = time.time() - start
    results["operations"].append(("math_calc", math_time, total))
    
    return results

# 复杂数据处理函数
def complex_data_pipeline(data_list, processors):
    """复杂数据处理管道"""
    results = []
    
    for data in data_list:
        processed = data
        for processor in processors:
            if callable(processor):
                processed = processor(processed)
            elif isinstance(processor, dict):
                # 字典处理器：应用多个函数
                for key, func in processor.items():
                    if callable(func):
                        processed = {**processed, key: func(processed)}
        
        results.append(processed)
    
    return results

# 全局测试函数
def run_all_tests():
    """运行所有测试"""
    print("=== 开始复杂测试 ===")
    
    # 测试1: 复杂数据结构
    print("\n1. 测试复杂数据结构...")
    data1 = ComplexData("test1", {"a": 1, "b": 2})
    data1.add_record("c", 3)
    print(f"数据1: {data1.data}, 历史: {len(data1.history)}")
    
    data2 = ComplexData.create_from_dict("test2", {"x": 10, "y": 20})
    merged = ComplexData.merge_instances(data1, data2)
    print(f"合并数据: {merged.data}")
    
    # 测试2: 数学运算
    print("\n2. 测试数学运算...")
    math = MathOperations(5)
    results = [
        math.calculate("add", 1, 2, 3),
        math.calculate("multiply", 2, 3, 4),
        math.calculate("complex", 1.57, 0, 2)
    ]
    print(f"数学结果: {results}")
    
    # 测试3: 树结构
    print("\n3. 测试树结构...")
    root = TreeNode("root")
    child1 = TreeNode("child1")
    child2 = TreeNode("child2")
    grandchild = TreeNode("grandchild")
    
    child1.add_child(grandchild)
    root.add_child(child1)
    root.add_child(child2)
    
    def visitor(value, depth):
        return f"{'  ' * depth}{value}"
    
    traversal = root.traverse(visitor)
    print("树遍历:")
    for line in traversal:
        print(line)
    
    # 测试4: 错误处理
    print("\n4. 测试错误处理...")
    error_gen = ErrorGenerator()
    errors = []
    for error_type in ["division_by_zero", "index_error", "key_error"]:
        try:
            error_gen.generate_error(error_type)
        except Exception as e:
            errors.append(str(e))
    
    print(f"捕获的错误: {errors[:3]}")
    
    # 测试5: 性能测试
    print("\n5. 性能测试...")
    perf_results = performance_test(100)
    for op_name, op_time, _ in perf_results["operations"]:
        print(f"  {op_name}: {op_time:.6f}秒")
    
    print("\n=== 复杂测试完成 ===")
    return {
        "data_test": len(merged.data) > 0,
        "math_test": any(r is not None for r in results),
        "tree_test": len(traversal) == 4,
        "error_test": len(errors) == 3,
        "perf_test": perf_results["iterations"] == 100
    }

if __name__ == "__main__":
    test_results = run_all_tests()
    print(f"\n测试结果: {test_results}")
    all_passed = all(test_results.values())
    print(f"所有测试通过: {all_passed}")
