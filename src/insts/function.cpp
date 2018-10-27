/* This file is part of the sirit project.
 * Copyright (c) 2018 ReinUsesLisp
 * This software may be used and distributed according to the terms of the GNU
 * Lesser General Public License version 2.1 or any later version.
 */

#include "sirit/sirit.h"
#include "insts.h"

namespace Sirit {

Ref Module::Function(Ref result_type, spv::FunctionControlMask function_control, Ref function_type) {
    auto op{new Op{spv::Op::OpFunction, bound++, result_type}};
    op->Add(static_cast<u32>(function_control));
    op->Add(function_type);
    return AddCode(op);
}

Ref Module::FunctionEnd() {
    return AddCode(spv::Op::OpFunctionEnd);
}

} // namespace Sirit