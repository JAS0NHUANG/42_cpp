template<typename T>
class Array {
	public:
		Array(void);
		~Array(void);

		Array(unsigned int n);
		Array(Array & toCopy);

		unsigned int size(void) const;

	private:
		T				*_array;
		unsigned int	_size;
}
