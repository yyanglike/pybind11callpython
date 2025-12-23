# ScriptInterpreter 重构计划

## 当前问题
1. `script_interpreter.cpp` 文件过大（约1500行），包含多个职责：
   - ANTLR visitor 实现
   - Python 交互逻辑
   - 表达式求值引擎
   - 错误处理
   - 变量管理

2. 代码结构不够清晰，难以维护和团队协作。

## 重构目标
1. 模块化分离，每个模块职责单一
2. 增加清晰的注释和文档
3. 提高代码可读性和可维护性
4. 便于团队协作开发

## 模块划分

### 1. 核心模块
- `script_interpreter_core.cpp/h` - 主解释器类，协调各个模块
- `ast_visitor.cpp/h` - ANTLR visitor 实现，语法树遍历
- `expression_evaluator.cpp/h` - 表达式求值引擎
- `python_bridge.cpp/h` - Python 交互桥梁
- `variable_manager.cpp/h` - 变量和作用域管理
- `error_handler.cpp/h` - 错误处理和报告

### 2. 辅助模块
- `script_value.cpp/h` - ScriptValue 类实现（已存在）
- `logger.cpp/h` - 日志系统（已存在）
- `utils.cpp/h` - 工具函数

## 重构步骤

### 第一阶段：创建文件结构和接口
1. 创建新的头文件和源文件框架
2. 定义清晰的接口和职责
3. 保持向后兼容性

### 第二阶段：逐步迁移功能
1. 迁移错误处理逻辑到 error_handler
2. 迁移变量管理到 variable_manager
3. 迁移Python交互到 python_bridge
4. 迁移表达式求值到 expression_evaluator
5. 迁移visitor实现到 ast_visitor

### 第三阶段：整合和测试
1. 更新主解释器使用新模块
2. 确保所有测试通过
3. 添加单元测试

## 注释和文档标准
1. 每个头文件必须有清晰的模块说明
2. 每个类必须有使用示例和注意事项
3. 复杂算法需要详细注释
4. 关键函数需要参数和返回值说明
5. 使用Doxygen格式注释

## 时间估计
- 第一阶段：1-2天
- 第二阶段：3-5天  
- 第三阶段：1-2天

## 风险控制
1. 每次只迁移一小部分功能
2. 频繁运行测试确保不破坏现有功能
3. 保持git提交的原子性
4. 及时进行代码审查
