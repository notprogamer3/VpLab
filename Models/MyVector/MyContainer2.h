using namespace std;

template<class T>
class ItemList {
public:
	// сохраним имеющийся тип рабочего объекта
	typedef T objType;

	// конструктор по умолчанию
	ItemList() = default;

	// явный конструктор принимающий значение
	explicit ItemList(T v) : m_value(v) {
	}

	// перегруженный конструктор принимающий
	// значение и указатель на предидущий элемент
	ItemList(T v, ItemList<T> *p_b) : m_value(v), m_back(p_b) {
	}

	// перегруженный конструктор принимающий
	// значение и указатели на предидущий и следующий элементы
	ItemList(T v, ItemList<T> *p_b, ItemList<T> *p_n) : m_value(v), m_back(p_b),
	                                                    m_next(p_n) {
	}

	// делегирующий конструктор копий
	// принимающий ссылку на константный объект
	ItemList(const ItemList<T> &it) : ItemList<T>(it.m_value, it.m_back,
	                                              it.m_next) {
	}

	// метод установки значения
	void set(T v) {
		m_value = v;
	}

	// метод получения значения
	T get() {
		return m_value;
	}


	// метод установки указателя на след. эл.
	void setNext(ItemList<T> *p_n) {
		m_next = p_n;
	}

	// метод получения указателя на след. эл.
	ItemList<T> *getNext() {
		return m_next;
	}

	// метод установки указателя на пред. эл.
	void setBack(ItemList<T> *p_b) {
		m_back = p_b;
	}

	// метод получения указателя на пред. эл.
	ItemList<T> *getBack() {
		return m_back;
	}

	// добавим дружественную функцию перегрузки
	// оператора вывода элемента на консоль
	friend ostream &operator<<(ostream &out, const ItemList<T> &it) {
		cout << it.m_value << endl;
		return out;
	}

private:
	T m_value{};
	ItemList<T> *m_next{};
	ItemList<T> *m_back{};
};

template<class T>
class MyList {
public:
	template<class V>
	class IteratorList {

		// делаем внешний класс дружественным к подклассу
		// чтобы он имел доступ к нашим закрытым свойствам
		friend class MyList<V>;

	public:
		// пишем конструктор копирования
		// который будет производить инициализацию членов класса
		// тело конструктора будет пустым
		IteratorList<V>(const IteratorList<V> &it) : m_item(it.m_item) {
		}

		// перегружаем оператор сравнения
		bool operator==(const IteratorList<V> &it) const {
			return m_item == it.m_item;
		}

		// перегружаем оператор сравнения на не
		bool operator!=(const IteratorList<V> &it) const {
			return m_item != it.m_item;
		}

		// перегружаем оператор икремента
		IteratorList<V> &operator++() {
			m_item = m_item->getNext();
			return *this;
		}

		// перегружаем оператор разыменования указателя
		V &operator*() const {
			return *m_item;
		}

	private:
		V *m_item{};
		// создаём закрытый конструктор инициализации членов класса
		explicit IteratorList(V *p) : m_item(p) {
		}
	};

	typedef IteratorList<T> iterator;
	typedef IteratorList<T> const_iterator;

	// конструктор по умолчанию
	MyList() = default;

	// явный конструктор
	explicit MyList(T *it) {
		initList(*it);
	}

	// возврат итератора на первый элемент
	iterator begin() {
		return iterator(m_start);
	}

	// возврат итератора на за-последний элемент
	iterator end() {
		return iterator(m_end);
	}

	// возврат константного итератора на первый элемент
	const_iterator begin() const {
		return const_iterator(m_start);
	}

	// возврат константного итератора на за-последний элемент
	const_iterator end() const {
		return const_iterator(m_end);
	}

	// метод очистки списка
	void erase() {
		for (int i{}; i < m_len; ++i) {
			m_start = m_start->getNext();
			delete m_start->getBack();
		}
		delete m_end;
		m_start = m_end = nullptr;
		m_len = 0;

	}

	~MyList() {
		erase();
	}

	// добавим дружественную функцию перегрузки оператора вывода списка на консоль
	friend ostream &operator<<(ostream &out, const MyList<T> &lst) {
		if (lst.isEmpty()) {
			out << "List is empty" << endl;
			return out;
		}
		for (const ItemList<typename T::objType> &it: lst) {
			out << it << endl;
		}
		return out;
	}

	// не будем реализовывать конструктор копий
	MyList(const MyList<T> &lst) = delete;

	// метод проверки на пустоту
	bool isEmpty() const {
		return !m_start;
	}

	// метод получения размера списка
	size_t len() {
		return m_len;
	}

	// метод добавления элемента в конец списка
	void add(T *it) {
		if (isEmpty()) {
			initList(*it);
		} else {

			m_end->getBack()->setNext(it);
			it->setNext(m_end);
			m_end->setBack(it);
			++m_len;
		}
	}

	// метод добавления элемента в начало списка
	void pushStart(T *it) {
		if (isEmpty()) {
			initList(*it);
		} else {
			it->setNext(m_start);
			m_start = it;
			++m_len;
		}
	}

	// метод удаления эл. с конца
	void delEnd() {
		if (isEmpty()) {
			return;
		} else if (len() == 1) {
			delete m_start;
			m_start = nullptr;
			delete m_end;
			m_end = nullptr;
			m_len = 0;
		} else {
			m_end->setBack(m_end->getBack()->getBack());
			delete m_end->getBack()->getNext();
			m_end->getBack()->setNext(m_end);


			--m_len;
		}
	}

	// метод удаления эл. с начала
	void delStart() {
		if (isEmpty()) {
			return;
		} else if (len() == 1) {
			delete m_start;
			m_start = nullptr;
			delete m_end;
			m_end = nullptr;
			m_len = 0;
		} else {
			m_start = m_start->getNext();
			delete m_start->getBack();
			m_start->setBack(nullptr);
			--m_len;
		}
	}

private:
	T *m_start{};
	T *m_end{};
	size_t m_len{};
	// приватный метод инициализации списка
	void initList(T &it) {
		m_start = &it;
		m_end = new T(0, m_start);
		it.setNext(m_end);
		m_len = 1;
	}
};
