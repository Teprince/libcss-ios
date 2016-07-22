CSS_PROPS_DIR=./libcss/src/parse/properties
CSS_BUILD_DIR=./build
UTILS_DIR=./libparserutils
BUILD_CC=gcc
AUTOGEN_PARSERS:= $(shell perl -pe '$$_="" unless /^([^\#][^:]+):/;$$_=$$1 . " "' $(CSS_PROPS_DIR)/properties.gen)

define gen_prop_parser

$1_auto_gen: $(CSS_PROPS_DIR)/properties.gen $(CSS_BUILD_DIR)/gen_parser
	$(CSS_BUILD_DIR)/gen_parser -o $(CSS_PROPS_DIR)/autogenerated_$1.c '$(shell grep "^$1:" $(CSS_PROPS_DIR)/properties.gen)'

endef

all: gen_build_dir gen_aliases gen_parser gen_source 

$(eval $(foreach PROP,$(AUTOGEN_PARSERS),$(call gen_prop_parser,$(PROP))))

AUTOGEN_DEP=$(addsuffix _auto_gen, $(AUTOGEN_PARSERS))


gen_parser: $(CSS_PROPS_DIR)/css_property_parser_gen.c 
	$(BUILD_CC) -o $(CSS_BUILD_DIR)/gen_parser $^

gen_source:$(AUTOGEN_DEP)
	@echo “gen $@”

gen_aliases:
	cd $(UTILS_DIR); perl ./build/make-aliases.pl;


gen_build_dir:
	@if test ! -d $(CSS_BUILD_DIR) ; \
	then \
		mkdir $(CSS_BUILD_DIR) ; \
	fi

.PHONY : clean
clean:
	rm -fr $(CSS_BUILD_DIR)
	rm -fr $(CSS_PROPS_DIR)/autogenerated_*.c
	rm -fr $(UTILS_DIR)/src/charset/aliases.inc