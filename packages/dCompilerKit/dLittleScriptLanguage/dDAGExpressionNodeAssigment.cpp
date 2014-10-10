/* Copyright (c) <2009> <Newton Game Dynamics>
*
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely
*/

#include "dLSCstdafx.h"
#include "dDAG.h"
#include "dDAGTypeNode.h"
#include "dDAGDimensionNode.h"
#include "dDAGExpressionNodeAssigment.h"

dInitRtti(dDAGExpressionNodeAssigment);

dDAGExpressionNodeAssigment::dDAGExpressionNodeAssigment(dList<dDAG*>& allNodes, dDAGExpressionNodeVariable* const leftVariable, dDAGExpressionNode* const expression)
	:dDAGExpressionNode(allNodes)
	,m_expression(expression)
	,m_leftVariable(leftVariable)
{
}


dDAGExpressionNodeAssigment::~dDAGExpressionNodeAssigment()
{
}

void dDAGExpressionNodeAssigment::ConnectParent(dDAG* const parent)  
{
	m_parent = parent;
	m_expression->ConnectParent(this);
	m_leftVariable->ConnectParent(this);
}


dCIL::dReturnValue dDAGExpressionNodeAssigment::Evalue(const dDAGFunctionNode* const function)
{
dAssert (0);
return dCIL::dReturnValue();
/*
	dCIL::dReturnValue val (m_expression->Evalue(function));
	dAssert (!m_leftVariable->m_dimExpressions.GetCount());

	if (m_leftVariable->m_type->m_intrinsicType != val.m_type) {
		// see if is ok to do cast promotions
		dAssert (0);
	}
	return val;
*/
}

void dDAGExpressionNodeAssigment::CompileCIL(dCIL& cil)  
{
dAssert (0);
/*
	m_expression->CompileCIL(cil); 
	if (m_leftVariable->m_dimExpressions.GetCount()) {
		dDAGDimensionNode* const dim = m_leftVariable->m_dimExpressions.GetFirst()->GetInfo();
		dim->CompileCIL(cil);

		dString result = dim->m_result.m_label;
		for (dList<dDAGDimensionNode*>::dListNode* node = m_leftVariable->m_dimExpressions.GetFirst()->GetNext(); node; node = node->GetNext()) {
			dAssert (0);
			dDAGDimensionNode* const dim = node->GetInfo();
			dim->CompileCIL(cil);
#if 0			
			dCILInstr& stmtMul = cil.NewStatement()->GetInfo();
			stmtMul.m_instruction = dCILInstr::m_assigment;
			stmtMul.m_operator = dCILInstr::m_mul;
			stmtMul.m_arg0.m_label = cil.NewTemp();
			stmtMul.m_arg1.m_label = result;
			stmtMul.m_arg2.m_label = dim->m_arraySize;

			DTRACE_INTRUCTION (&stmtMul);

			dCILInstr& stmtAdd = cil.NewStatement()->GetInfo();
			stmtAdd.m_instruction = dCILInstr::m_assigment;
			stmtAdd.m_operator = dCILInstr::m_add;
			stmtAdd.m_arg0.m_label = cil.NewTemp();
			stmtAdd.m_arg1.m_label = stmtMul.m_arg0.m_label;
			stmtAdd.m_arg2 = dim->m_result;

			result = stmtAdd.m_arg0.m_label;

			DTRACE_INTRUCTION (&stmtAdd);
#endif
		}

		dAssert (m_leftVariable->m_parent);
		dTree<dCILInstr::dArg, dString>::dTreeNode* const variable = dDAG::FindLocalVariable(m_leftVariable->m_name);
		dAssert (variable);
		dCILInstr::dArg arg1 (LoadLocalVariable(cil, variable->GetInfo()));
		dCILInstr::dArg arg0 (LoadLocalVariable(cil, m_expression->m_result));

		dAssert (m_parent);
		// emit an indirect addressing mode
		dCILInstr& tmp = cil.NewStatement()->GetInfo();
		tmp.m_instruction = dCILInstr::m_store;
		tmp.m_arg0 = arg0;
		tmp.m_arg1 = arg1;
		tmp.m_arg2 = dim->m_result;
		DTRACE_INTRUCTION (&tmp);
		m_result = tmp.m_arg0; 
	} else {
		m_leftVariable->CompileCIL(cil); 
		dCILInstr::dArg arg1 (LoadLocalVariable(cil, m_expression->m_result));
		dCILInstr& stmt = cil.NewStatement()->GetInfo();
		stmt.m_instruction = (m_leftVariable->m_result.m_label.Find(m_scopePrefix) == 0) ? dCILInstr::m_storeBase : stmt.m_instruction = dCILInstr::m_assigment;
		stmt.m_arg0 = m_leftVariable->m_result;
		stmt.m_arg1 = arg1;
		DTRACE_INTRUCTION (&stmt);
	}
*/
}


dDAGExpressionNodeVariable* dDAGExpressionNodeAssigment::FindLeftVariable()
{
	return m_leftVariable->FindLeftVariable();
}