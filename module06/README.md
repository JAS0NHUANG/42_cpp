## Conversion
Implicite promotion (OK)
	- Cast a type from less precise type to more precise type. Ex: int to double.
Implicite demotion (NO)
	- Cast a type from more precise type to less precise type. Ex: float to int.


## Upcast and Downcast

Implicite Upcast -> OK!
Implicite Downcast -> NO!!!


## Static Cast

```
static_cast<int>(theNbr);
```

## Dynamic cast
- Runtime casting!! (all other cast are done at compilation.)
- Only works on polymorphic class type.(At least one virtual member function.)

Normaly used to DOWNCAST(base to derived) an object pointer or referencec.

RTTI?? (Run Time Type Info) Information saved inside a class about the type information.

## Cast Operators

```
class Converter {
	public:
		Converter(float const nbr) : _nbr(nbr) {}
		operator float() { return this->_nbr; } 
		operator int() { return static_cast<int>( this->_nbr); }

	private:
		float	_nbr;
};
```

## string to number types
int, float or double. (This will help, but won’t do the whole job!)

`stold`, `stof`, `stod`, `stoi`, `stol`

## reinterpret_cast
used to cast pointer or reference?
```
float a = 42.42f

void* b = &a; // promotion?
int* c = reinterpret_cast<int*>(b); // demotion?
int& d = reinterpret_cast<int&>(b); // demotion?
```

retyping?

the 'uintptr_t' type
https://stackoverflow.com/questions/1845482/what-is-uintptr-t-data-type


