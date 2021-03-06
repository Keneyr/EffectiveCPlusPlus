## Customizing new and delete. (定制new和delete)

### 49. Understand the behaviour of the new-handler. (了解new-handler的行为)

### 50. Understand when it makes sense to replace new and delete. (了解new和delete的合理替换时机)

### 51. Adhere to convension when writing new and delete. (编写new和delete时需固守常规)



### 52. Write placement delete if you write placement new. (写了placement new也要写placement delete) 


```cpp
Widget* pw = new Widget;
```
new的过程分两步：

1.分配内存的operator new

2.Widget的default构造函数

如果构造函数过程中抛出异常，此时pw尚未被赋值，客户手上也没有指针指向该被归还的内存，这样就会造成内存泄露。

如果是默认正常的operator new，系统会找到具有相同参数的operator delete，取消内存分配动作并恢复旧观。但如果是用户重载的placement new，就需要写一个对应的placement delete。

```cpp
class Widget{
public:
    static void* operator new (std::size_t size, std::ostream& logStream) throw(std::bad_alloc);
    static void* operator delete(void*, std::ostream&) throw(std::bad_alloc);
};
Widget* pw = new(std::cerr)Wdiget;
```