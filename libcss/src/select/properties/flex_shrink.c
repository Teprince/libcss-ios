//
//  flex_shrink.c
//  libcss
//
//  Created by Teprince on 7/23/16.
//  Copyright © 2016 Teprince. All rights reserved.
//

#include "bytecode/bytecode.h"
#include "bytecode/opcodes.h"
#include "select/propset.h"
#include "select/propget.h"
#include "utils/utils.h"

#include "select/properties/properties.h"
#include "select/properties/helpers.h"

css_error css__cascade_flex_shrink(uint32_t opv, css_style* style,
        css_select_state* state)
{
    uint16_t value = CSS_FLEX_SHRINK_INHERIT;
    css_fixed index = 0;
    
    if (isInherit(opv) == false) {
        value = CSS_FLEX_SHRINK_SET;
        
        index = *((css_fixed*)style->bytecode);
        advance_bytecode(style, sizeof(index));
        index >>= 10;
    }
    
    if (css__outranks_existing(getOpcode(opv), isImportant(opv), state,
                               isInherit(opv))) {
        return set_flex_shrink(state->computed, value, index);
    }
    
    return CSS_OK;
}

css_error css__set_flex_shrink_from_hint(const css_hint* hint,
        css_computed_style* style)
{
    return set_flex_shrink(style, hint->status, hint->data.integer);
}

css_error css__initial_flex_shrink(css_select_state* state)
{
    return set_flex_shrink(state->computed, CSS_FLEX_SHRINK_SET, 0);
}

css_error css__compose_flex_shrink(const css_computed_style* parent,
        const css_computed_style* child,
        css_computed_style* result)
{
    int32_t value = 0;
    uint8_t type = get_flex_shrink(child, &value);

    if (type == CSS_FLEX_SHRINK_INHERIT) {
        type = get_flex_shrink(parent, &value);
    }

    return set_flex_shrink(result, type, value);
}
