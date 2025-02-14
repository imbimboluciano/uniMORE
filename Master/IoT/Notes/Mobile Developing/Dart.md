Supporta la tipizizzazione dinamica

Data Types in Dart programming language
```dart
const age = 27; //you can't change the value (compile time and runtime)
final name = 'Foo'; //
var name = 'Alex';

```

```dart
String getFullName(String firstName, String lastName){
	//return firstName + ' ' + lastName;
	return '$firstName $lastName'; //using camel case in dart
} 

String getFullName(String firstName, String lastName) => '$firstName $lastName'; 



void test(){
	var age = 20;

final ageMinusOne = --age;

print(age);

print(ageMinusOne);

}

final name = 'Foo';
final nameTimes20 = name * 20;
print(nameTimes20);
```


```dart
final names = ['Foo', 'Bar', 'Baz']; //list of homogenous things
names.length; //proporties of data type list

final names = {'Foo'}; //set (unique things

final person = {'age':20, 'name':'Foo'}; //map (key-value)

```


Concepts of sound null-safety 
We can have the concept of absence of value (null = keyword)


The Dart language enforces sound null safety.

Null safety prevents errors that result from unintentional access of variables set to `null`.

For example, if a method expects an integer but receives `null`, your app causes a runtime error. This type of error, a null dereference error, can be difficult to debug.

With sound null safety, all variables require a value. This means Dart considers all variables _non-nullable_. You can assign values of the declared type only, like `int i=42`. You can never assign a value of `null` to default variable types. To specify that a variable type can have a `null` value, add a `?` after the type annotation: `int? i`. These specific types can contain either a `null` _or_ a value of the defined type.

Sound null safety changes potential **runtime errors** into **edit-time** analysis errors. With null safety, the Dart analyzer and compilers flag if a non-nullable variable has either:

- Not been initialized with a non-null value
- Been assigned a `null` value. These checks allows you to fix these errors _before_ deploying your app.

```dart
	int? aNullableInt = null;
	List<String>? names = null;
	List<String?> persons = ['jdeded',null];
	List<String?>? children = null;


	const String? firstName = null;
	const String? lastName = 'Foo';
	const firstNonNullValue = firstName ?? lastName; //pick the first non-value values
	
String? name = firstName;
name ??= lastName; //if name is null dart try to assign to him the value of lastName (if is not null) otherwise it does nothing

void test(List<String>? names){
	final length = names?.length ?? 0;
}
```

If you don’t know that an expression with a nullable type equals `null` or not, you can use the conditional member access operator (`?.`). This operator evaluates to `null` if the target expression resolves to `null`. Otherwise, it accesses the property on the non-null target value.

```dart
// The following calls the 'action' method only if nullableObject is not null
nullableObject?.action();
```


Enumerated types, often called _enumerations_ or _enums_, are a special kind of class used to represent a fixed number of constant values.
```dart
enum PersonProperties{ firstName,lastName, age}
enum Color { red, green, blue}
```

Object in Dart
```dart
class Person{
	Person(this.firstName,this.lastName); // constructor
	void run(){
		print("Running");
	}

	void breathe(){
		print("Breathing");
	}
}

class PoliceOfficer extends Person{}

abstract class Person{}

person = Person();
```

Factory Constructors.
Use the `factory` keyword when implementing a constructor that doesn’t always create a new instance of its class.
```dart
class Cat{

final String name;

Cat(this.name);

factory Cat.fluffBall(){

return Cat('Fluff Ball2');

}

}

final fluffBall = Cat.fluffBall();
```

Custom Operators
```dart
class Cat extends Object{
	final String name;
	Cat(this.name);

	@override
	bool operator ==(covariant Cat other) => other.name == name;

	@override
	int get hashCode => super.hashCode;
}
```


Extensions
Extension methods add functionality to existing libraries
```dart
extension NumberParsing on String {
  int parseInt() {
    return int.parse(this);
  }
  // ···
}
```

Future
A future (lower case “f”) is an instance of the [Future](https://api.dart.dev/stable/dart-async/Future-class.html) (capitalized “F”) class. A future represents the result of an asynchronous operation, and can have two states: uncompleted or completed.
When you call an asynchronous function, it returns an uncompleted future. That future is waiting for the function’s asynchronous operation to finish or to throw an error.
If the asynchronous operation succeeds, the future completes with a value. Otherwise, it completes with an error.


```dart
Future<void> fetchUserOrder() {
  // Imagine that this function is fetching user info from another service or database.
  return Future.delayed(const Duration(seconds: 2), () => print('Large Latte'));
  // after 2 seconds the function print Large Latte
}

void main() {
  fetchUserOrder();
  print('Fetching user order...');
}
```

The `async` and `await` keywords provide a declarative way to define asynchronous functions and use their results. Remember these two basic guidelines when using `async` and `await`:

- **To define an async function, add `async` before the function body:**
- **The `await` keyword works only in `async` functions.**

```dart
Future<String> createOrderMessage() async {
  var order = await fetchUserOrder();
  return 'Your order is: $order';
}

Future<String> fetchUserOrder() =>
    // Imagine that this function is
    // more complex and slow.
    Future.delayed(
      const Duration(seconds: 2),
      () => 'Large Latte',
    );

Future<void> main() async {
  print('Fetching user order...');
  print(await createOrderMessage());
}
```


Stream
Like the future but periodically return a value.
```dart
Stream<String> getName(){

return Stream.periodic(const Duration(seconds: 1), (value){

return 'Foo';

});

}

  
  

void test() async{

await for (final value in getName()){

print(value);

}

print('Stream finished working');

}
```

Generators and Iterable
```dart
Iterable<int> getOneTwoThree() sync*{

yield 1;

yield 2;

yield 3;

  

}

  
  

void test(){

for(final value in getOneTwoThree()){

print(value);

}

}
```

Generics 
To avoid re-writing similar code. Generics let you share a single interface and implementation between many types, while still taking advantage of static analysis.

```dart
class Pair<A,B>{
final A value1;
final B value2;
Pair(this.value1,this.value2)
}

abstract class Cache<T> {
  T getByKey(String key);
  void setByKey(String key, T value);
}
```
