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

css_error css__cascade_flex_shrink(uint32_t opv, css_style *style,
                                   css_select_state *state)
{
    return CSS_OK;
}

css_error css__set_flex_shrink_from_hint(const css_hint *hint,
                                        css_computed_style *style)
{
    UNUSED(hint);
    UNUSED(style);
    
    return CSS_OK;
}

css_error css__initial_flex_shrink(css_select_state *state)
{
    UNUSED(state);
    
    return CSS_OK;
}

css_error css__compose_flex_shrink(const css_computed_style *parent,
                                   const css_computed_style *child,
                                   css_computed_style *result)
{
    UNUSED(parent);
    UNUSED(child);
    UNUSED(result);
    
    return CSS_OK;
}


