template<class T>
class Przyklad {
	T dane_;
public:
	bool jest_duże() const {
		return sizeof(T)>sizeof(double);
	}
	void wyluskaj(){
		*dane_;
	}
};

int main() {
	Przyklad<int> a;
	return a.jest_duże();
}