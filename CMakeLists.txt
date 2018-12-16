cmake_minimum_required(VERSION 3.12)
project(flight)

set(CMAKE_CXX_STANDARD 14)

add_executable(flight main.cpp lexer1.cpp lexer1.h command.h openServerCommand.cpp openServerCommand.h Expression.h BinaryExpression.cpp BinaryExpression.h Mul.cpp Mul.h Div.cpp Div.h Plus.cpp Plus.h Minus.cpp Minus.h Num.cpp Num.h DataReaderServer.cpp DataReaderServer.h Maps.cpp Maps.h Parser.cpp Parser.h DefineVarCommand.cpp DefineVarCommand.h)