#
# Makefile

.PHONY: all iutest internal util listener impl gtest

IUTEST_HPP=$(wildcard ../../include/*.hpp)
INTERNAL_HPP=$(wildcard ../../include/internal/*.hpp)
UTIL_HPP=$(wildcard ../../include/util/*.hpp)
LISTENER_HPP=$(wildcard ../../include/listener/*.hpp)
IMPL_HPP=$(wildcard ../../include/impl/*.ipp)
GTEST_HPP=$(wildcard ../../include/gtest/*.hpp) $(wildcard ../../include/gtest/switch/*.hpp)

SUPPRESS_WHITESPACE_SUB=/tab,/indent,/braces,/comments,/newline,/labels,/operators,/parens
SUPPRESS_WHITESPACE=$(subst /,-whitespace/,$(SUPPRESS_WHITESPACE_SUB))
SUPPRESS_BUILD=-build/include_what_you_use,-build/c++11
SUPPRESS_READABILITY=-readability/todo,-readability/braces,-readability/function
SUPPRESS_RUNTIME=-runtime/int,-runtime/references
SUPPRESS=$(SUPPRESS_BUILD),$(SUPPRESS_WHITESPACE),$(SUPPRESS_READABILITY),$(SUPPRESS_RUNTIME)

all: iutest internal impl listener util gtest

iutest: $(IUTEST_HPP) cpplint.py Makefile
	python cpplint.py --extensions=hpp,cpp --linelength=150 --filter=$(SUPPRESS) $(IUTEST_HPP)

internal: $(INTERNAL_HPP) cpplint.py Makefile
	python cpplint.py --extensions=hpp,cpp --linelength=150 --filter=$(SUPPRESS) $(INTERNAL_HPP)

util: $(UTIL_HPP) cpplint.py Makefile
	python cpplint.py --extensions=hpp,cpp --linelength=150 --filter=$(SUPPRESS) $(UTIL_HPP)

listener: $(LISTENER_HPP) cpplint.py Makefile
	python cpplint.py --extensions=hpp,cpp --linelength=120 --filter=$(SUPPRESS) $(LISTENER_HPP)

impl: $(IMPL_HPP) cpplint.py Makefile
	python cpplint.py --extensions=ipp     --linelength=150 --filter=$(SUPPRESS) $(IMPL_HPP)

gtest: $(GTEST_HPP) cpplint.py Makefile
	python cpplint.py --extensions=hpp,cpp --linelength=150 --filter=$(SUPPRESS),-build/include $(GTEST_HPP)

cpplint.py:
	git clone https://github.com/google/styleguide.git cpplint
	cp cpplint/cpplint/cpplint.py cpplint.py
	rm -rf cpplint