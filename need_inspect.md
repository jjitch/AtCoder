```cpp
int i = 0;
auto func = [&](int i){return i+10;};
```

# Behavior of smart pointers

メンバにポインタを持つ（ユニークポインタとして）インスタンスをスタックに積んだ後、そのスコープを抜けてインスタンスは破棄されたときに、メンバのデストラクタも呼び出される？

呼び出されるっぽい

```cpp
class some_heap
{
private:
public:
	~some_heap() { cout << "Destructed!" << endl; }
};

class p_holder
{
private:
	unique_ptr<some_heap> ptr;

public:
	p_holder() : ptr(new some_heap()) {}
};

int main()
{
	p_holder a;
}
```
When this program is executed, "Destructed!" will be shown in standard output.

# containers as a return value
It's well-known that passing the containers like `vector<T>` to the function in the way of `f(vector<T> a)` may cause heavy copy.
Here, what happens if the containers are returned from functions?
Will it be copied or moved?
```cpp
vi f()
{
	vi a = {10, 120, 4314};
	cout << &a << " " << &a[0] << endl;
	return a;
}

int main()
{
	vi a = f();
	cout << &a << " " << &a[0] << endl;
}
```
In conslusion, move happens.
In two scope, main and f, the same address has been shown.