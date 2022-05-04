# Notions:  

## Orthodox Canonical Form
https://www.francescmm.com/orthodox-canonical-class-form/  
https://wiki.c2.com/?CanonicalForm  
https://en.wikipedia.org/wiki/Jim_Coplien  

James O. Coplien, 1992, Advanced C₊₊ programming styles and idioms, Chapter 3, Section 2 (pp. 44)
[book link](https://archive.org/details/advancedcbsprogr00copl/page/44/mode/2up)

What should be included:  
- Default constructor
- Copy constructor
- Destructor
- Copy assignment operator

## Copy constructor
```
ClassName(const ClassName &theObject);
```

then inside the function, asign the "theObject" to "this"
```
*this = theObject;
```

## Copy assignment operator
operator overloading 
```
ClassName &ClassName::operation=(const ClassName &object);
```

## Fixed-point number

## increment / decrement operator overloading
https://www.tutorialspoint.com/cplusplus/increment_decrement_operators_overloading.htm
