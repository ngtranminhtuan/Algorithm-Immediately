//Linear recursive: Its structure is the same as the definition:

  KieuDuLieu TenHam(Thamso) {
    if (Dieu Kieu Dung) {
      ...;
      return Gia tri tra ve;
    }
    ...;
    TenHam(Thamso)
      ...;
    ...;
  }

  //-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
 //Binary recursive: The same as linear recursive BUT inside of function of its which Add a callback to itself

KieuDuLieu TenHam(Thamso) {
    if (Dieu Kieu Dung) {
      ...;
      return Gia tri tra ve;
    }
    ...;
    TenHam(Thamso);
    ...;
    ...;
    TenHam(Thamso);
    ...;
    ...;
  }

  //-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
//2-functions-recursive: 2-functions-recursive has 2 function, AND inside function 1 callback function 2, and reverse!
//STOP condition and return value of 2 functions CAN The same or Different

KieuDuLieu TenHamX(Thamso) {
  if (Dieu Kieu Dung) {
    ...;
    return Gia tri tra ve;
  }
  ...;
  return TenHamX(Thamso) < Lien ket hai ham > TenHamY(Thamso);
}

KieuDuLieu TenHamY(Thamso) {
    if (Dieu Kieu Dung) {
      ...;
      return Gia tri tra ve;
    }
    ...;
    return TenHamY(Thamso) < Lien ket hai ham > TenHamX(Thamso);
  }

 // -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
//Non-linear recursive: Inside of function and inside loop which have callback function of its

KieuDuLieu TenHam(Thamso) {
  if (Dieu Kieu Dung) {
    ...;
    return Gia tri tra ve;
  }
  ...;
  vonglap(dieu kieu lap) {
    ...TenHam(Thamso)...;
  }
  return Gia tri tra ve;
}