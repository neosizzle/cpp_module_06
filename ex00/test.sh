make fclean
make
echo "==========NORMAL TESTS=============="
echo "1"
./a.out 1
echo ""
echo "-69"
./a.out -69
echo ""
echo "69"
./a.out 69
echo ""
echo "69.0"
./a.out 69.0
echo ""
echo "-69.0"
./a.out -69.0
echo ""
echo "420.69"
./a.out 420.69
echo ""
echo "420.69f"
./a.out 420.69f
echo ""
echo "a"
./a.out a
echo ""
echo "42012312313123123131231231231231231.0f"
./a.out 42012312313123123131231231231231231.0f
echo ""
echo "-42012312313123123131231231231231231.0f"
./a.out -42012312313123123131231231231231231.0f
echo ""
echo "42012312313123123131231231231231231.123"
./a.out 42012312313123123131231231231231231.123
echo ""
echo "-42012312313123123131231231231231231.123"
./a.out -42012312313123123131231231231231231.123
echo ""
echo "inf"
./a.out inf
echo ""
echo "inff"
./a.out inff
echo ""
echo "-inff"
./a.out -inff
echo ""
echo "+inff"
./a.out +inff
echo ""
echo "-inf"
./a.out -inf
echo ""
echo "+inf"
./a.out +inf
echo ""
echo "nan"
./a.out nan
echo ""
echo "nanf"
./a.out nanf
echo ""
echo "-inf"
./a.out -inf
echo ""
echo "+inf"
./a.out +inf
echo ""
echo "nan"
./a.out nan
echo ""
echo "nanf"
./a.out nanf
echo ""
echo "====================================="
echo "==========ERROR TESTS================"
echo "abc"
./a.out abc
echo ""
echo "123abc"
./a.out 123abc
echo ""
echo "123."
./a.out 123.
echo ""
echo "123.f"
./a.out 123.f
echo ""
echo "12.3."
./a.out 12.3.
echo ""
echo "no args"
./a.out
echo ""
echo "====================================="

make fclean