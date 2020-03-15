
#pragma once

namespace fortran {

  template <class T> YAKL_INLINE int  size(T &arr, int dim) { return arr.get_dimensions()(dim); }
  template <class T> YAKL_INLINE int  size(T &arr) { return arr.totElems(); }
  template <class T> YAKL_INLINE auto shape(T &arr) { return arr.get_dimensions(); }
  template <class T> YAKL_INLINE bool allocated (T &arr) { return arr.myData != nullptr; }
  template <class T> YAKL_INLINE bool associated (T &arr) { return arr.myData != nullptr; }
  template <class T> YAKL_INLINE int  lbound (T &arr, int dim) { return arr.get_lbounds()(dim); }
  template <class T> YAKL_INLINE auto lbound (T &arr) { return arr.get_lbounds(); }
  template <class T> YAKL_INLINE int  ubound (T &arr, int dim) { return arr.get_ubounds()(dim); }
  template <class T> YAKL_INLINE auto ubound (T &arr) { return arr.get_ubounds(); }



  template <class T> YAKL_INLINE T constexpr epsilon(T) { return std::numeric_limits<T>::epsilon(); }
  template <class T, int rank, int myMem, int myStyle> YAKL_INLINE T constexpr epsilon(Array<T,rank,myMem,myStyle> &arr) { return std::numeric_limits<T>::epsilon(); }
  template <class T, class D0, class D1, class D2, class D3> YAKL_INLINE T constexpr epsilon(FSArray<T,D0,D1,D2,D3> &arr) { return std::numeric_limits<T>::epsilon(); }

  template <class T> YAKL_INLINE T constexpr tiny(T) { return std::numeric_limits<T>::min(); }
  template <class T, int rank, int myMem, int myStyle> YAKL_INLINE T constexpr tiny(Array<T,rank,myMem,myStyle> &arr) { return std::numeric_limits<T>::min(); }
  template <class T, class D0, class D1, class D2, class D3> YAKL_INLINE T constexpr tiny(FSArray<T,D0,D1,D2,D3> &arr) { return std::numeric_limits<T>::min(); }

  template <class T> YAKL_INLINE T constexpr huge(T) { return std::numeric_limits<T>::max(); }
  template <class T, int rank, int myMem, int myStyle> YAKL_INLINE T constexpr huge(Array<T,rank,myMem,myStyle> &arr) { return std::numeric_limits<T>::max(); }
  template <class T, class D0, class D1, class D2, class D3> YAKL_INLINE T constexpr huge(FSArray<T,D0,D1,D2,D3> &arr) { return std::numeric_limits<T>::max(); }



  template <class T> YAKL_INLINE T sign(T val) { return val >= 0 ? 1 : -1; }
  template <class T> YAKL_INLINE T mod(T a, T b) { return a - ((int)(a/b) * b); }



  template <class T> YAKL_INLINE T merge(T t, T f, bool cond) { return cond ? t : f; }



  template <class T, int rank, int myMem, int myStyle> YAKL_INLINE T minval( Array<T,rank,myMem,myStyle> &arr ) {
    T m = arr.myData[0];
    for (int i=1; i<arr.totElems(); i++) {
      if (arr.myData[i] < m) { m = arr.myData[i]; }
    }
    return m;
  }
  template <class T, class D0, class D1, class D2, class D3> YAKL_INLINE T minval( FSArray<T,D0,D1,D2,D3> &arr ) {
    T m = arr.myData[0];
    for (int i=1; i<arr.totElems(); i++) {
      if (arr.myData[i] < m) { m = arr.myData[i]; }
    }
    return m;
  }
  template <class T, int myMem, int myStyle> YAKL_INLINE int minloc( Array<T,1,myMem,myStyle> &arr ) {
    T m = arr.myData[0];
    int loc = lbound(arr,1);
    for (int i=lbound(arr,1); i<=ubound(arr,1); i++) {
      if (arr(i) < m) {
        m = arr(i);
        loc = i;
      }
    }
    return loc;
  }
  template <class T, class D0> YAKL_INLINE int minloc( FSArray<T,D0> &arr ) {
    T m = arr.myData[0];
    int loc = lbound(arr,1);
    for (int i=lbound(arr,1); i<=ubound(arr,1); i++) {
      if (arr(i) < m) {
        m = arr(i);
        loc = i;
      }
    }
    return loc;
  }



  template <class T, int rank, int myMem, int myStyle> YAKL_INLINE T maxval( Array<T,rank,myMem,myStyle> &arr ) {
    T m = arr.myData[0];
    for (int i=1; i<arr.totElems(); i++) {
      if (arr.myData[i] > m) { m = arr.myData[i]; }
    }
    return m;
  }
  template <class T, class D0, class D1, class D2, class D3> YAKL_INLINE T maxval( FSArray<T,D0,D1,D2,D3> &arr ) {
    T m = arr.myData[0];
    for (int i=1; i<arr.totElems(); i++) {
      if (arr.myData[i] > m) { m = arr.myData[i]; }
    }
    return m;
  }
  template <class T, int myMem, int myStyle> YAKL_INLINE int maxloc( Array<T,1,myMem,myStyle> &arr ) {
    T m = arr.myData[0];
    int loc = lbound(arr,1);
    for (int i=lbound(arr,1); i<=ubound(arr,1); i++) {
      if (arr(i) > m) {
        m = arr(i);
        loc = i;
      }
    }
    return loc;
  }
  template <class T, class D0> YAKL_INLINE int maxloc( FSArray<T,D0> &arr ) {
    T m = arr.myData[0];
    int loc = lbound(arr,1);
    for (int i=lbound(arr,1); i<=ubound(arr,1); i++) {
      if (arr(i) > m) {
        m = arr(i);
        loc = i;
      }
    }
    return loc;
  }



  template <class T, int rank, int myMem, int myStyle> YAKL_INLINE T sum( Array<T,rank,myMem,myStyle> &arr ) {
    T m = arr.myData[0];
    for (int i=1; i<arr.totElems(); i++) { m += arr.myData[i]; }
    return m;
  }
  template <class T, class D0, class D1, class D2, class D3> YAKL_INLINE T sum( FSArray<T,D0,D1,D2,D3> &arr ) {
    T m = arr.myData[0];
    for (int i=1; i<arr.totElems(); i++) { m += arr.myData[i]; }
    return m;
  }



  template <class T, int rank, int myMem, int myStyle> YAKL_INLINE T product( Array<T,rank,myMem,myStyle> &arr ) {
    T m = arr.myData[0];
    for (int i=1; i<arr.totElems(); i++) { m *= arr.myData[i]; }
    return m;
  }
  template <class T, class D0, class D1, class D2, class D3> YAKL_INLINE T product( FSArray<T,D0,D1,D2,D3> &arr ) {
    T m = arr.myData[0];
    for (int i=1; i<arr.totElems(); i++) { m *= arr.myData[i]; }
    return m;
  }



  template <class F, class T, int rank, int myMem, int myStyle> YAKL_INLINE bool any( Array<T,rank,myMem,myStyle> &arr , F const &f , T val ) {
    bool ret = false;
    for (int i=0; i<arr.totElems(); i++) {
      if ( f( arr.myData[i] , val ) ) { ret = true; }
    }
    return ret;
  }
  template <class T, int rank, int myMem, int myStyle> YAKL_INLINE bool anyLT ( Array<T,rank,myMem,myStyle> &arr , T val ) {
    auto test = [](T elem , T val)->bool { return elem <  val; };
    return any( arr , test , val );
  }
  template <class T, int rank, int myMem, int myStyle> YAKL_INLINE bool anyLTE( Array<T,rank,myMem,myStyle> &arr , T val ) {
    auto test = [](T elem , T val)->bool { return elem <= val; };
    return any( arr , test , val );
  }
  template <class T, int rank, int myMem, int myStyle> YAKL_INLINE bool anyGT ( Array<T,rank,myMem,myStyle> &arr , T val ) {
    auto test = [](T elem , T val)->bool { return elem >  val; };
    return any( arr , test , val );
  }
  template <class T, int rank, int myMem, int myStyle> YAKL_INLINE bool anyGTE( Array<T,rank,myMem,myStyle> &arr , T val ) {
    auto test = [](T elem , T val)->bool { return elem >= val; };
    return any( arr , test , val );
  }
  template <class T, int rank, int myMem, int myStyle> YAKL_INLINE bool anyEQ ( Array<T,rank,myMem,myStyle> &arr , T val ) {
    auto test = [](T elem , T val)->bool { return elem == val; };
    return any( arr , test , val );
  }



  template <class F, class T, class D0, class D1, class D2, class D3> YAKL_INLINE bool any( FSArray<T,D0,D1,D2,D3> &arr , F const &f , T val ) {
    bool ret = false;
    for (int i=0; i<arr.totElems(); i++) {
      if ( f( arr.myData[i] , val ) ) { ret = true; }
    }
    return ret;
  }
  template <class T, class D0, class D1, class D2, class D3> YAKL_INLINE bool anyLT ( FSArray<T,D0,D1,D2,D3> &arr , T val ) {
    auto test = [](T elem , T val)->bool { return elem <  val; };
    return any( arr , test , val );
  }
  template <class T, class D0, class D1, class D2, class D3> YAKL_INLINE bool anyLTE( FSArray<T,D0,D1,D2,D3> &arr , T val ) {
    auto test = [](T elem , T val)->bool { return elem <= val; };
    return any( arr , test , val );
  }
  template <class T, class D0, class D1, class D2, class D3> YAKL_INLINE bool anyGT ( FSArray<T,D0,D1,D2,D3> &arr , T val ) {
    auto test = [](T elem , T val)->bool { return elem >  val; };
    return any( arr , test , val );
  }
  template <class T, class D0, class D1, class D2, class D3> YAKL_INLINE bool anyGTE( FSArray<T,D0,D1,D2,D3> &arr , T val ) {
    auto test = [](T elem , T val)->bool { return elem >= val; };
    return any( arr , test , val );
  }
  template <class T, class D0, class D1, class D2, class D3> YAKL_INLINE bool anyEQ ( FSArray<T,D0,D1,D2,D3> &arr , T val ) {
    auto test = [](T elem , T val)->bool { return elem == val; };
    return any( arr , test , val );
  }

}

