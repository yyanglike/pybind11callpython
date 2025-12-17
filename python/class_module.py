"""
测试Python类的模块
"""

class SimpleClass:
    """一个简单的测试类"""
    
    class_attribute = "I am a class attribute"
    
    def __init__(self, name="default", value=0):
        """构造函数"""
        self.name = name
        self.value = value
        self._private_attr = "private"
    
    def instance_method(self, multiplier=1):
        """实例方法"""
        return f"{self.name}: {self.value * multiplier}"
    
    def get_private(self):
        """获取私有属性"""
        return self._private_attr
    
    def set_private(self, value):
        """设置私有属性"""
        self._private_attr = value
        return self._private_attr
    
    @classmethod
    def class_method(cls):
        """类方法"""
        return f"Class method called, class_attribute={cls.class_attribute}"
    
    @staticmethod
    def static_method(param):
        """静态方法"""
        return f"Static method called with param={param}"
    
    def __str__(self):
        return f"SimpleClass(name={self.name}, value={self.value})"


class Calculator:
    """计算器类"""
    
    def __init__(self, initial_value=0):
        self.value = initial_value
    
    def add(self, x):
        self.value += x
        return self.value
    
    def subtract(self, x):
        self.value -= x
        return self.value
    
    def multiply(self, x):
        self.value *= x
        return self.value
    
    def divide(self, x):
        if x == 0:
            raise ValueError("Cannot divide by zero")
        self.value /= x
        return self.value
    
    def reset(self):
        self.value = 0
        return self.value


class Person:
    """人类，演示继承"""
    
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def introduce(self):
        return f"My name is {self.name} and I am {self.age} years old."
    
    def have_birthday(self):
        self.age += 1
        return self.age


class Student(Person):
    """学生类，继承自Person"""
    
    def __init__(self, name, age, student_id):
        super().__init__(name, age)
        self.student_id = student_id
        self.grades = []
    
    def add_grade(self, grade):
        self.grades.append(grade)
        return self.grades
    
    def average_grade(self):
        if not self.grades:
            return 0
        return sum(self.grades) / len(self.grades)
    
    def introduce(self):
        base_intro = super().introduce()
        return f"{base_intro} My student ID is {self.student_id}."


# 模块级别的函数，用于测试混合调用
def create_person(name, age):
    """创建一个人的实例"""
    return Person(name, age)


def create_student(name, age, student_id):
    """创建一个学生的实例"""
    return Student(name, age, student_id)


# 测试代码
if __name__ == "__main__":
    # 测试SimpleClass
    obj = SimpleClass("test", 10)
    print(obj.instance_method(2))
    print(SimpleClass.class_method())
    print(SimpleClass.static_method("hello"))
    
    # 测试Calculator
    calc = Calculator(10)
    print(f"Calculator add: {calc.add(5)}")
    print(f"Calculator multiply: {calc.multiply(2)}")
    
    # 测试Person和Student
    person = Person("Alice", 30)
    print(person.introduce())
    
    student = Student("Bob", 20, "S12345")
    print(student.introduce())
    student.add_grade(90)
    student.add_grade(85)
    print(f"Average grade: {student.average_grade()}")
