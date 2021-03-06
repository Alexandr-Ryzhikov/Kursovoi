//
// Created by SKolody on 21.08.2019.
//

#ifndef REGISTERS_SUSUDEFS_HPP
#define REGISTERS_SUSUDEFS_HPP

#include <type_traits>
//#define __forceinline  _Pragma("inline=forced")
#define __forceinline

#define __flashdata _Pragma("location = \".flash\"")

struct SusuStringView
{
    const char * str;
    std::size_t size;

    template <std::size_t N>
    explicit constexpr SusuStringView(char const (&s)[N])
        : str(s)
        , size(N - 1) 
    {
    }
};



template <typename... Types>
struct TypesList{} ;

template<typename... args>
struct Attributes
{
  private:
    template<typename TAttr, typename T = void, typename... arg>
    struct Attr
    {
      using Type = typename std::conditional<std::is_same<TAttr, T>::value, T, typename Attr<TAttr, arg...>::Type>::type;
    };

    template<typename TAttr>
    struct Attr<TAttr, void>
    {
      using Type = void;
    };

  public:
    template<typename T>
    using Attribute = typename Attr<T, args...>::Type;

    template<typename T>
    static constexpr bool HasAttribute()
    {
      return !std::is_same<Attribute<T>, void>::value;
    }
};

#endif //REGISTERS_SUSUDEFS_HPP
