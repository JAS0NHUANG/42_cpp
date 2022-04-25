## Module01

## Allocation on stack or heap

```
TheClass Hohoho; // on the stack
TheClass *Hohoho = new TheClass(); // on the heap
```

Instances created on the stack will be destroyed automaticly when leaving the scope.
To destroy the instances created on the heap:
```
delete Hohoho;
```
As simple as that :D

## ex00

## ex01
1. instancialize X amount of objects with an array.  
`Zombie the_horde = new Zombie[X];`

2. [delete an array of objects](https://stackoverflow.com/questions/2486034/delete-an-array-of-objects)
`delete[] the_horde;`

3. https://stackoverflow.com/questions/9377407/displaying-the-address-of-a-string


## ex02
### reference vs value
```
int	myNumber = 7;
int	*myNumberPtr = &myNumber;
int	&myNumberRef = myNumber;
```
- A reference can never point to NULL, and it can't be reasigned to another address.  
- But we can change the value inside that address.  
```
myNumberRef = 77;
```
- Return the "reference".  

## ex03
Usage of pointer and reference
* Be careful! The `getType()` function must return a "const reference" to type.

## ex04
### fstream
```
sdt::fstream theFile;
theFile.open(path, mode)
