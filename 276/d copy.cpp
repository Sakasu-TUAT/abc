#line 2 "library/other/template.hpp"

#include <bits/stdc++.h>
#line 2 "library/template/macros.hpp"

#line 4 "library/template/macros.hpp"

#ifndef __COUNTER__
#define __COUNTER__ __LINE__
#endif

#define REP_SELECTER(a, b, c, d, e, ...) e
#define REP1_0(b, c) REP1_1(b, c)
#define REP1_1(b, c)                                                           \
    for (ll REP_COUNTER_##c = 0; REP_COUNTER_##c < (ll)(b); ++REP_COUNTER_##c)
#define REP1(b) REP1_0(b, __COUNTER__)
#define REP2(i, b) for (ll i = 0; i < (ll)(b); ++i)
#define REP3(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define REP4(i, a, b, c) for (ll i = (ll)(a); i < (ll)(b); i += (ll)(c))
#define rep(...) REP_SELECTER(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)
#define RREP2(i, a) for (ll i = (ll)(a)-1; i >= 0; --i)
#define RREP3(i, a, b) for (ll i = (ll)(a)-1; i >= (ll)(b); --i)
#define RREP4(i, a, b, c) for (ll i = (ll)(a)-1; i >= (ll)(b); i -= (ll)(c))
#define rrep(...) REP_SELECTER(__VA_ARGS__, RREP4, RREP3, RREP2)(__VA_ARGS__)
#define REPS2(i, b) for (ll i = 1; i <= (ll)(b); ++i)
#define REPS3(i, a, b) for (ll i = (ll)(a) + 1; i <= (ll)(b); ++i)
#define REPS4(i, a, b, c) for (ll i = (ll)(a) + 1; i <= (ll)(b); i += (ll)(c))
#define reps(...) REP_SELECTER(__VA_ARGS__, REPS4, REPS3, REPS2)(__VA_ARGS__)
#define RREPS2(i, a) for (ll i = (ll)(a); i > 0; --i)
#define RREPS3(i, a, b) for (ll i = (ll)(a); i > (ll)(b); --i)
#define RREPS4(i, a, b, c) for (ll i = (ll)(a); i > (ll)(b); i -= (ll)(c))
#define rreps(...)                                                             \
    REP_SELECTER(__VA_ARGS__, RREPS4, RREPS3, RREPS2)(__VA_ARGS__)

#define each_for(...) for (auto&& __VA_ARGS__)
#define each_const(...) for (const auto& __VA_ARGS__)

#define all(v) std::begin(v), std::end(v)
#if __cplusplus >= 201402L
#define rall(v) std::rbegin(v), std::rend(v)
#else
#define rall(v) v.begin(), v.end()
#endif

#if __cpp_constexpr >= 201304L
#define CONSTEXPR constexpr
#else
#define CONSTEXPR
#endif

#if __cpp_if_constexpr >= 201606L
#define IF_CONSTEXPR constexpr
#else
#define IF_CONSTEXPR
#endif

#define IO_BUFFER_SIZE 2048
#line 2 "library/template/alias.hpp"

#line 4 "library/template/alias.hpp"

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PLL = std::pair<ll, ll>;
template<class T>
using prique = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<class T> class infinity {
public:
    static constexpr T value = std::numeric_limits<T>::max() / 2;
    static constexpr T mvalue = std::numeric_limits<T>::min() / 2;
    static constexpr T max = std::numeric_limits<T>::max();
    static constexpr T min = std::numeric_limits<T>::min();
};

#if __cplusplus <= 201402L
template<class T> constexpr T infinity<T>::value;
template<class T> constexpr T infinity<T>::mvalue;
template<class T> constexpr T infinity<T>::max;
template<class T> constexpr T infinity<T>::min;
#endif

#if __cpp_variable_templates >= 201304L
template<class T> constexpr T INF = infinity<T>::value;
#endif

constexpr ll inf = infinity<ll>::value;
constexpr ld EPS = 1e-8;
constexpr ld PI = 3.1415926535897932384626;
#line 2 "library/template/type_traits.hpp"

#line 5 "library/template/type_traits.hpp"

template<class T, class... Args> struct function_traits_impl {
    using result_type = T;
    template<std::size_t idx>
    using argument_type =
        typename std::tuple_element<idx, std::tuple<Args...>>::type;
    using argument_tuple = std::tuple<Args...>;
    static constexpr std::size_t arg_size() { return sizeof...(Args); }
};

template<class> struct function_traits_helper;

template<class Res, class Tp, class... Args>
struct function_traits_helper<Res (Tp::*)(Args...)> {
    using type = function_traits_impl<Res, Args...>;
};
template<class Res, class Tp, class... Args>
struct function_traits_helper<Res (Tp::*)(Args...)&> {
    using type = function_traits_impl<Res, Args...>;
};
template<class Res, class Tp, class... Args>
struct function_traits_helper<Res (Tp::*)(Args...) const> {
    using type = function_traits_impl<Res, Args...>;
};
template<class Res, class Tp, class... Args>
struct function_traits_helper<Res (Tp::*)(Args...) const&> {
    using type = function_traits_impl<Res, Args...>;
};

#if __cpp_noexcept_function_type >= 201510L
template<class Res, class Tp, class... Args>
struct function_traits_helper<Res (Tp::*)(Args...) noexcept> {
    using type = function_traits_impl<Res, Args...>;
};
template<class Res, class Tp, class... Args>
struct function_traits_helper<Res (Tp::*)(Args...)& noexcept> {
    using type = function_traits_impl<Res, Args...>;
};
template<class Res, class Tp, class... Args>
struct function_traits_helper<Res (Tp::*)(Args...) const noexcept> {
    using type = function_traits_impl<Res, Args...>;
};
template<class Res, class Tp, class... Args>
struct function_traits_helper<Res (Tp::*)(Args...) const& noexcept> {
    using type = function_traits_impl<Res, Args...>;
};
#endif

template<class F>
using function_traits =
    typename function_traits_helper<decltype(&F::operator())>::type;


template<class T, class = void> struct is_range : std::false_type {};
template<class T>
struct is_range<
    T,
    decltype(all(std::declval<typename std::add_lvalue_reference<T>::type>()),
             (void)0)> : std::true_type {};

template<class T, bool = is_range<T>::value>
struct range_rank : std::integral_constant<std::size_t, 0> {};
template<class T>
struct range_rank<T, true>
    : std::integral_constant<std::size_t,
                             range_rank<typename T::value_type>::value + 1> {};

template<std::size_t size> struct int_least {
    static_assert(size <= 128, "size must be less than or equal to 128");

    using type = typename std::conditional<
        size <= 8, std::int_least8_t,
        typename std::conditional<
            size <= 16, std::int_least16_t,
            typename std::conditional<
                size <= 32, std::int_least32_t,
                typename std::conditional<size <= 64, std::int_least64_t,
                                          __int128_t>::type>::type>::type>::
        type;
};

template<std::size_t size> using int_least_t = typename int_least<size>::type;

template<std::size_t size> struct uint_least {
    static_assert(size <= 128, "size must be less than or equal to 128");

    using type = typename std::conditional<
        size <= 8, std::uint_least8_t,
        typename std::conditional<
            size <= 16, std::uint_least16_t,
            typename std::conditional<
                size <= 32, std::uint_least32_t,
                typename std::conditional<size <= 64, std::uint_least64_t,
                                          __uint128_t>::type>::type>::type>::
        type;
};

template<std::size_t size> using uint_least_t = typename uint_least<size>::type;

template<class T>
using double_size_int = int_least<std::numeric_limits<T>::digits * 2 + 1>;
template<class T> using double_size_int_t = typename double_size_int<T>::type;
template<class T>
using double_size_uint = uint_least<std::numeric_limits<T>::digits * 2>;
template<class T> using double_size_uint_t = typename double_size_uint<T>::type;

template<class T>
using double_size = std::conditional<std::is_signed<T>::value,
                                     double_size_int<T>, double_size_uint<T>>;
template<class T> using double_size_t = typename double_size<T>::type;
#line 2 "library/template/in.hpp"

#line 6 "library/template/in.hpp"
#include <unistd.h>

template<std::size_t buf_size = IO_BUFFER_SIZE> class Reader {
private:
    int fd, idx, sz;
    bool state;
    std::array<char, buf_size> buffer;
    inline void read_buf() {
        sz = read(fd, buffer.begin(), buf_size);
        idx = 0;
        if (sz < 0) throw std::runtime_error("input failed");
    }

public:
    static constexpr int get_buf_size() { return buf_size; }
    Reader() noexcept : fd(0), idx(0), sz(0), state(true) {}
    Reader(int fd) noexcept : fd(fd), idx(0), sz(0), state(true) {}
    Reader(FILE* fp) noexcept : fd(fileno(fp)), idx(0), sz(0), state(true) {}

    class iterator {
    private:
        Reader* reader;

    public:
        using difference_type = void;
        using value_type = void;
        using pointer = void;
        using reference = void;
        using iterator_category = std::input_iterator_tag;

        iterator() : reader(nullptr) {}
        explicit iterator(Reader& reader) : reader(&reader) {}
        explicit iterator(Reader* reader) : reader(reader) {}

        iterator& operator++() {
            if (reader->idx == reader->sz) reader->read_buf();
            ++reader->idx;
            return *this;
        }
        iterator operator++(int) {
            iterator res = *this;
            ++(*this);
            return res;
        }
        char operator*() const {
            if (reader->idx == reader->sz) reader->read_buf();
            if (reader->idx < reader->sz) return reader->buffer[reader->idx];
            reader->state = false;
            return '\0';
        }
        bool rdstate() const { return reader->state; }
    };

    iterator begin() noexcept { return iterator(this); }
};

Reader<> reader(0);

template<class Iterator, std::size_t decimal_precision = 16> class Scanner {
public:
    using iterator_type = Iterator;

private:
    template<class, class = void> struct has_scan : std::false_type {};
    template<class T>
    struct has_scan<
        T, decltype(std::declval<T>().scan(std::declval<Scanner&>()), (void)0)>
        : std::true_type {};
    Iterator itr;

public:
    Scanner() = default;
    Scanner(const Iterator& itr) : itr(itr) {}

    inline void discard_space() {
        while (('\t' <= *itr && *itr <= '\r') || *itr == ' ') ++itr;
    }
    void scan(char& a) {
        discard_space();
        a = *itr;
        ++itr;
    }
    void scan(bool& a) {
        discard_space();
        a = *itr != '0';
        ++itr;
    }
    void scan(std::string& a) {
        discard_space();
        a.clear();
        while ((*itr < '\t' || '\r' < *itr) && *itr != ' ' && *itr != '\0') {
            a += *itr;
            ++itr;
        }
    }
    template<std::size_t len> void scan(std::bitset<len>& a) {
        discard_space();
        rrep (i, len) {
            a[i] = *itr != '0';
            ++itr;
        }
    }
    template<class T,
             typename std::enable_if<std::is_integral<T>::value &&
                                     !has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        discard_space();
        bool sgn = false;
        if IF_CONSTEXPR (std::is_signed<T>::value) {
            if (*itr == '-') {
                sgn = true;
                ++itr;
            }
        }
        a = 0;
        while ('0' <= *itr && *itr <= '9') {
            a = a * 10 + *itr - '0';
            ++itr;
        }
        if IF_CONSTEXPR (std::is_signed<T>::value) {
            if (sgn) a = -a;
        }
    }
    template<class T,
             typename std::enable_if<std::is_floating_point<T>::value &&
                                     !has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        discard_space();
        bool sgn = false;
        if (*itr == '-') {
            sgn = true;
            ++itr;
        }
        a = 0;
        while ('0' <= *itr && *itr <= '9') {
            a = a * 10 + *itr - '0';
            ++itr;
        }
        if (*itr == '.') {
            ++itr;
            T n = 0, d = 1;
            for (int i = 0;
                 '0' <= *itr && *itr <= '9' && i < (int)decimal_precision;
                 ++i) {
                n = n * 10 + *itr - '0';
                d *= 10;
                ++itr;
            }
            while ('0' <= *itr && *itr <= '9') ++itr;
            a += n / d;
        }
        if (sgn) a = -a;
    }

private:
    template<std::size_t i, class... Args> void scan(std::tuple<Args...>& a) {
        if IF_CONSTEXPR (i < sizeof...(Args)) {
            scan(std::get<i>(a));
            scan<i + 1, Args...>(a);
        }
    }

public:
    template<class... Args> void scan(std::tuple<Args...>& a) {
        scan<0, Args...>(a);
    }
    template<class T, class U> void scan(std::pair<T, U>& a) {
        scan(a.first);
        scan(a.second);
    }
    template<class T,
             typename std::enable_if<is_range<T>::value &&
                                     !has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        each_for (i : a) scan(i);
    }
    template<class T,
             typename std::enable_if<has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        a.scan(*this);
    }

    void operator()() {}
    template<class Head, class... Args>
    void operator()(Head& head, Args&... args) {
        scan(head);
        operator()(args...);
    }

    template<class T> Scanner& operator>>(T& a) {
        scan(a);
        return *this;
    }

    explicit operator bool() const { return itr.rdstate(); }
};

Scanner<Reader<>::iterator> scan(reader.begin());
#line 2 "library/template/out.hpp"

#line 7 "library/template/out.hpp"

template<std::size_t buf_size = IO_BUFFER_SIZE> class Writer {
private:
    int fd, idx;
    std::array<char, buf_size> buffer;
    inline void write_buf() {
        int num = write(fd, buffer.begin(), idx);
        idx = 0;
        if (num < 0) throw std::runtime_error("output failed");
    }

public:
    Writer() noexcept : fd(1), idx(0) {}
    Writer(int fd) noexcept : fd(fd), idx(0) {}
    Writer(FILE* fp) noexcept : fd(fileno(fp)), idx(0) {}

    ~Writer() { write_buf(); }

    class iterator {
    private:
        Writer* writer;

    public:
        using difference_type = void;
        using value_type = void;
        using pointer = void;
        using reference = void;
        using iterator_category = std::output_iterator_tag;

        iterator() noexcept : writer(nullptr) {}
        explicit iterator(Writer& writer) noexcept : writer(&writer) {}
        explicit iterator(Writer* writer) noexcept : writer(writer) {}

        iterator& operator++() {
            ++writer->idx;
            if (writer->idx == buf_size) writer->write_buf();
            return *this;
        }
        iterator operator++(int) {
            iterator res = *this;
            ++(*this);
            return res;
        }
        char& operator*() const { return writer->buffer[writer->idx]; }
        void flush() const { writer->write_buf(); }
    };

    iterator begin() noexcept { return iterator(this); }
};

Writer<> writer(1), ewriter(2);

template<class Iterator, bool debug = false> class Printer {
public:
    using iterator_type = Iterator;

private:
    template<class, bool = debug, class = void>
    struct has_print : std::false_type {};
    template<class T>
    struct has_print<T, false,
                     decltype(std::declval<T>().print(std::declval<Printer&>()),
                              (void)0)> : std::true_type {};
    template<class T>
    struct has_print<T, true,
                     decltype(std::declval<T>().debug(std::declval<Printer&>()),
                              (void)0)> : std::true_type {};
    Iterator itr;
    std::size_t decimal_precision;

public:
    void print_char(char c) {
        *itr = c;
        ++itr;
    }

    void flush() { itr.flush(); }

    Printer() noexcept = default;
    explicit Printer(const Iterator& itr) noexcept
        : itr(itr), decimal_precision(16) {}

    void set_decimal_precision(std::size_t decimal_precision) {
        this->decimal_precision = decimal_precision;
    }

    void print(char c) {
        if IF_CONSTEXPR (debug) print_char('\'');
        print_char(c);
        if IF_CONSTEXPR (debug) print_char('\'');
    }
    void print(bool b) { print_char((char)(b + '0')); }
    void print(const char* a) {
        if IF_CONSTEXPR (debug) print_char('"');
        for (; *a != '\0'; ++a) print_char(*a);
        if IF_CONSTEXPR (debug) print_char('"');
    }
    template<std::size_t len> void print(const char (&a)[len]) {
        if IF_CONSTEXPR (debug) print_char('"');
        for (auto i : a) print_char(i);
        if IF_CONSTEXPR (debug) print_char('"');
    }
    void print(const std::string& a) {
        if IF_CONSTEXPR (debug) print_char('"');
        for (auto i : a) print_char(i);
        if IF_CONSTEXPR (debug) print_char('"');
    }
    template<std::size_t len> void print(const std::bitset<len>& a) {
        rrep (i, len) print_char((char)(a[i] + '0'));
    }
    template<class T,
             typename std::enable_if<std::is_integral<T>::value &&
                                     !has_print<T>::value>::type* = nullptr>
    void print(T a) {
        if (!a) {
            print_char('0');
            return;
        }
        if IF_CONSTEXPR (std::is_signed<T>::value) {
            if (a < 0) {
                print_char('-');
                a = -a;
            }
        }
        std::string s;
        while (a) {
            s += (char)(a % 10 + '0');
            a /= 10;
        }
        for (auto i = s.rbegin(); i != s.rend(); ++i) print_char(*i);
    }
    template<class T,
             typename std::enable_if<std::is_floating_point<T>::value &&
                                     !has_print<T>::value>::type* = nullptr>
    void print(T a) {
        if (a == std::numeric_limits<T>::infinity()) {
            print("inf");
            return;
        }
        if (a == -std::numeric_limits<T>::infinity()) {
            print("-inf");
            return;
        }
        if (std::isnan(a)) {
            print("nan");
            return;
        }
        if (a < 0) {
            print_char('-');
            a = -a;
        }
        T b = a;
        if (b < 1) {
            print_char('0');
        }
        else {
            std::string s;
            while (b >= 1) {
                s += (char)('0' + (int)std::fmod(b, 10.0));
                b /= 10;
            }
            for (auto i = s.rbegin(); i != s.rend(); ++i) print_char(*i);
        }
        print_char('.');
        rep (decimal_precision) {
            a *= 10;
            print_char((char)('0' + (int)std::fmod(a, 10.0)));
        }
    }

private:
    template<std::size_t i, class... Args>
    void print(const std::tuple<Args...>& a) {
        if IF_CONSTEXPR (i < sizeof...(Args)) {
            if IF_CONSTEXPR (debug) print_char(',');
            print_char(' ');
            print(std::get<i>(a));
            print<i + 1, Args...>(a);
        }
    }

public:
    template<class... Args> void print(const std::tuple<Args...>& a) {
        if IF_CONSTEXPR (debug) print_char('(');
        if IF_CONSTEXPR (sizeof...(Args) != 0) print(std::get<0>(a));
        print<1, Args...>(a);
        if IF_CONSTEXPR (debug) print_char(')');
    }
    template<class T, class U> void print(const std::pair<T, U>& a) {
        if IF_CONSTEXPR (debug) print_char('(');
        print(a.first);
        if IF_CONSTEXPR (debug) print_char(',');
        print_char(' ');
        print(a.second);
        if IF_CONSTEXPR (debug) print_char(')');
    }
    template<class T,
             typename std::enable_if<is_range<T>::value &&
                                     !has_print<T>::value>::type* = nullptr>
    void print(const T& a) {
        if IF_CONSTEXPR (debug) print_char('{');
        for (auto i = a.begin(); i != a.end(); ++i) {
            if (i != a.begin()) {
                if IF_CONSTEXPR (debug) print_char(',');
                print_char(' ');
            }
            print(*i);
        }
        if IF_CONSTEXPR (debug) print_char('}');
    }
    template<class T, typename std::enable_if<has_print<T>::value &&
                                              !debug>::type* = nullptr>
    void print(const T& a) {
        a.print(*this);
    }
    template<class T, typename std::enable_if<has_print<T>::value &&
                                              debug>::type* = nullptr>
    void print(const T& a) {
        a.debug(*this);
    }

    void operator()() {}
    template<class Head, class... Args>
    void operator()(const Head& head, const Args&... args) {
        print(head);
        operator()(args...);
    }

    template<class T> Printer& operator<<(const T& a) {
        print(a);
        return *this;
    }

    Printer& operator<<(Printer& (*pf)(Printer&)) { return pf(*this); }
};

template<class Iterator, bool debug>
Printer<Iterator, debug>& endl(Printer<Iterator, debug>& pr) {
    pr.print_char('\n');
    pr.flush();
    return pr;
}
template<class Iterator, bool debug>
Printer<Iterator, debug>& flush(Printer<Iterator, debug>& pr) {
    pr.flush();
    return pr;
}

struct SetPrec {
    int n;
    template<class Pr> void print(Pr& pr) const { pr.set_decimal_precision(n); }
    template<class Pr> void debug(Pr& pr) const { pr.set_decimal_precision(n); }
};
SetPrec setprec(int n) { return SetPrec{n}; };

Printer<Writer<>::iterator> print(writer.begin()), eprint(writer.begin());

template<class T> auto prints(const T& v) -> decltype(print << v, (void)0) {
    print << v;
    print.print_char('\n');
}

#ifdef SHIO_LOCAL
Printer<Writer<>::iterator, true> debug(writer.begin()),
    edebug(ewriter.begin());
#else
char debug_iterator_character;
class DebugIterator {
public:
    DebugIterator() noexcept = default;
    DebugIterator& operator++() { return *this; }
    DebugIterator& operator++(int) { return *this; }
    char& operator*() const { return debug_iterator_character; }
    void flush() const {}
};
Printer<DebugIterator> debug, edebug;
#endif
#line 2 "library/template/bitop.hpp"

#line 5 "library/template/bitop.hpp"

namespace bitop {

#define KTH_BIT(b, k) (((b) >> (k)) & 1)
#define POW2(k) (1ull << (k))

inline ull next_combination(int n, ull x) {
    if (n == 0) return 1;
    ull a = x & -x;
    ull b = x + a;
    return (x & ~b) / a >> 1 | b;
}

#define rep_comb(i, n, k)                                                      \
    for (ull i = (1ull << (k)) - 1; i < (1ull << (n));                         \
         i = bitop::next_combination((n), i))

inline CONSTEXPR int msb(ull x) {
    int res = x ? 0 : -1;
    if (x & 0xFFFFFFFF00000000) x &= 0xFFFFFFFF00000000, res += 32;
    if (x & 0xFFFF0000FFFF0000) x &= 0xFFFF0000FFFF0000, res += 16;
    if (x & 0xFF00FF00FF00FF00) x &= 0xFF00FF00FF00FF00, res += 8;
    if (x & 0xF0F0F0F0F0F0F0F0) x &= 0xF0F0F0F0F0F0F0F0, res += 4;
    if (x & 0xCCCCCCCCCCCCCCCC) x &= 0xCCCCCCCCCCCCCCCC, res += 2;
    return res + ((x & 0xAAAAAAAAAAAAAAAA) ? 1 : 0);
}

inline CONSTEXPR int ceil_log2(ull x) { return x ? msb(x - 1) + 1 : 0; }

} // namespace bitop

inline CONSTEXPR int popcnt(ull x) noexcept {
#if __cplusplus >= 202002L
    return std::popcount(x);
#endif
    x = (x & 0x5555555555555555) + ((x >> 1) & 0x5555555555555555);
    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);
    x = (x & 0x0f0f0f0f0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f0f0f0f0f);
    x = (x & 0x00ff00ff00ff00ff) + ((x >> 8) & 0x00ff00ff00ff00ff);
    x = (x & 0x0000ffff0000ffff) + ((x >> 16) & 0x0000ffff0000ffff);
    return (x & 0x00000000ffffffff) + ((x >> 32) & 0x00000000ffffffff);
}
#line 10 "library/other/template.hpp"

template<class T, class U>
std::ostream& operator<<(std::ostream& ost, const std::pair<T, U>& p) {
    return ost << p.first << ' ' << p.second;
}
template<class T, class U>
std::istream& operator>>(std::istream& ist, std::pair<T, U>& p) {
    return ist >> p.first >> p.second;
}

template<class Container, typename std::enable_if<!std::is_same<
                              Container, std::string>::value>::type* = nullptr>
auto operator<<(std::ostream& ost, const Container& cont)
    -> decltype(cont.begin(), cont.end(), ost) {
    for (auto itr = cont.begin(); itr != cont.end(); ++itr) {
        if (itr != cont.begin()) ost << ' ';
        ost << *itr;
    }
    return ost;
}
template<class Container, typename std::enable_if<!std::is_same<
                              Container, std::string>::value>::type* = nullptr>
auto operator>>(std::istream& ist, Container& cont)
    -> decltype(cont.begin(), cont.end(), ist) {
    for (auto itr = cont.begin(); itr != cont.end(); ++itr) ist >> *itr;
    return ist;
}

template<class T, class U>
inline constexpr bool chmin(T& a, const U& b) noexcept {
    return a > b ? a = b, true : false;
}
template<class T, class U>
inline constexpr bool chmax(T& a, const U& b) noexcept {
    return a < b ? a = b, true : false;
}
template<class T, class U, class Comp>
inline constexpr bool chmin(T& a, const U& b, Comp cmp) noexcept {
    return cmp(b, a) ? a = b, true : false;
}
template<class T, class U, class Comp>
inline constexpr bool chmax(T& a, const U& b, Comp cmp) noexcept {
    return cmp(a, b) ? a = b, true : false;
}

inline CONSTEXPR ll gcd(ll a, ll b) noexcept {
    while (b) {
        const ll c = a;
        a = b;
        b = c % b;
    }
    return a;
}
inline CONSTEXPR ll lcm(ll a, ll b) noexcept { return a / gcd(a, b) * b; }

inline CONSTEXPR bool is_prime(ll N) noexcept {
    if (N <= 1) return false;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}
inline std::vector<ll> prime_factor(ll N) {
    std::vector<ll> res;
    for (ll i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            res.push_back(i);
            N /= i;
        }
    }
    if (N != 1) res.push_back(N);
    return res;
}

inline CONSTEXPR ll my_pow(ll a, ll b) noexcept {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        b >>= 1;
        a *= a;
    }
    return res;
}
inline CONSTEXPR ll mod_pow(ll a, ll b, ll mod) {
    assert(mod > 0);
    if (mod == 1) return 0;
    a %= mod;
    ll res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        b >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

inline PLL extGCD(ll a, ll b) noexcept {
    const ll n = a, m = b;
    ll x = 1, y = 0, u = 0, v = 1;
    ll t;
    while (b) {
        t = a / b;
        std::swap(a -= t * b, b);
        std::swap(x -= t * u, u);
        std::swap(y -= t * v, v);
    }
    if (x < 0) {
        x += m;
        y -= n;
    }
    return {x, y};
}
inline ll mod_inv(ll a, ll mod) {
    ll b = mod;
    ll x = 1, u = 0;
    ll t;
    while (b) {
        t = a / b;
        std::swap(a -= t * b, b);
        std::swap(x -= t * u, u);
    }
    if (x < 0) x += mod;
    assert(a == 1);
    return x;
}
inline PLL ChineseRemainder(ll b1, ll m1, ll b2, ll m2) {
    const PLL p = extGCD(m1, m2);
    const ll g = p.first * m1 + p.second * m2;
    const ll l = m1 / g * m2;
    if ((b2 - b1) % g != 0) return PLL{-1, -1};
    const ll x = (b2 - b1) / g * p.first % (m2 / g);
    return {(x * m1 + b1 + l) % l, l};
}
PLL ChineseRemainders(const std::vector<ll>& b, const std::vector<ll>& m) {
    PLL res{0, 1};
    rep (i, b.size()) {
        res = ChineseRemainder(res.first, res.second, b[i], m[i]);
        if (res.first == -1) return res;
    }
    return res;
}

template<class F> class RecLambda {
private:
    F f;

public:
    explicit constexpr RecLambda(F&& f_) : f(std::forward<F>(f_)) {}
    template<class... Args>
    constexpr auto operator()(Args&&... args) const
        -> decltype(f(*this, std::forward<Args>(args)...)) {
        return f(*this, std::forward<Args>(args)...);
    }
};

template<class F> inline constexpr RecLambda<F> rec_lambda(F&& f) {
    return RecLambda<F>(std::forward<F>(f));
}

template<class Head, class... Tail> struct multi_dim_vector {
    using type = std::vector<typename multi_dim_vector<Tail...>::type>;
};
template<class T> struct multi_dim_vector<T> { using type = T; };

template<class T, class Arg>
constexpr std::vector<T> make_vec(int n, Arg&& arg) {
    return std::vector<T>(n, std::forward<Arg>(arg));
}
template<class T, class... Args>
constexpr typename multi_dim_vector<Args..., T>::type make_vec(int n,
                                                               Args&&... args) {
    return typename multi_dim_vector<Args..., T>::type(
        n, make_vec<T>(std::forward<Args>(args)...));
}

template<class T, class Comp = std::less<T>> class presser {
private:
    std::vector<T> dat;
    Comp cmp;
    bool sorted = false;

public:
    presser() : presser(Comp()) {}
    presser(const Comp& cmp) : cmp(cmp) {}
    presser(const std::vector<T>& vec, const Comp& cmp = Comp())
        : dat(vec), cmp(cmp) {}
    presser(std::vector<T>&& vec, const Comp& cmp = Comp())
        : dat(std::move(vec)), cmp(cmp) {}
    presser(std::initializer_list<T> il, const Comp& cmp = Comp())
        : dat(il.begin(), il.end()), cmp(cmp) {}
    void reserve(int n) {
        assert(!sorted);
        dat.reserve(n);
    }
    void push_back(const T& v) {
        assert(!sorted);
        dat.push_back(v);
    }
    void push_back(T&& v) {
        assert(!sorted);
        dat.push_back(std::move(v));
    }
    template<class... Args> void emplace_back(Args&&... args) {
        assert(!sorted);
        dat.emplace_back(std::forward<Args>(args)...);
    }
    void push(const std::vector<T>& vec) {
        assert(!sorted);
        const int n = dat.size();
        dat.resize(n + vec.size());
        rep (i, vec.size()) dat[n + i] = vec[i];
    }
    int build() {
        assert(!sorted);
        sorted = true;
        std::sort(all(dat), cmp);
        dat.erase(std::unique(all(dat),
                              [&](const T& a, const T& b) -> bool {
                                  return !cmp(a, b) && !cmp(b, a);
                              }),
                  dat.end());
        return dat.size();
    }
    const T& operator[](int k) const& {
        assert(sorted);
        assert(0 <= k && k < (int)dat.size());
        return dat[k];
    }
    T operator[](int k) && {
        assert(sorted);
        assert(0 <= k && k < (int)dat.size());
        return std::move(dat[k]);
    }
    int get(const T& val) const {
        assert(sorted);
        auto itr = std::lower_bound(all(dat), val, cmp);
        assert(itr != dat.end() && !cmp(val, *itr));
        return itr - dat.begin();
    }
    int lower_bound(const T& val) const {
        assert(sorted);
        auto itr = std::lower_bound(all(dat), val, cmp);
        return itr - dat.begin();
    }
    int upper_bound(const T& val) const {
        assert(sorted);
        auto itr = std::upper_bound(all(dat), val, cmp);
        return itr - dat.begin();
    }
    bool contains(const T& val) const {
        assert(sorted);
        return std::binary_search(all(dat), val, cmp);
    }
    std::vector<int> pressed(const std::vector<T>& vec) const {
        assert(sorted);
        std::vector<int> res(vec.size());
        rep (i, vec.size()) res[i] = get(vec[i]);
        return res;
    }
    void press(std::vector<T>& vec) const {
        static_assert(std::is_integral<T>::value,
                      "template argument must be convertible from int type");
        assert(sorted);
        each_for (i : vec) i = get(i);
    }
    int size() const {
        assert(sorted);
        return dat.size();
    }
    const std::vector<T>& data() const& { return dat; }
    std::vector<T> data() && { return std::move(dat); }
};
#line 2 "main.cpp"

using namespace std;

int main() {
    int N; scan >> N;
    vector<int> ans{0};
    rep (i, N) {
        int a; scan >> a;
        ans.push_back(ans[a - 1] + 1);
        ans.push_back(ans[a - 1] + 1);
    }
    each_const (i : ans) prints(i);
}
