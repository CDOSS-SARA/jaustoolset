/*
 * ex: set ro:
 * DO NOT EDIT.
 * generated by smc (http://smc.sourceforge.net/)
 * from file : NodeIDAllocator_SendFSM_sm.sm
 */

#include "urn_jaus_jss_iop_NodeIDAllocator_1_1/Messages/MessageSet.h"
#include "urn_jaus_jss_iop_NodeIDAllocator_1_1/NodeIDAllocator_SendFSM.h"
#include "include/urn_jaus_jss_iop_NodeIDAllocator_1_1/NodeIDAllocator_SendFSM_sm.h"

using namespace statemap;

namespace urn_jaus_jss_iop_NodeIDAllocator_1_1
{
    // Static class declarations.
    NodeIDAllocator_SendFSM_SM_Sending NodeIDAllocator_SendFSM_SM::Sending("NodeIDAllocator_SendFSM_SM::Sending", 0);
    NodeIDAllocator_SendFSM_SM_Internally_Generated_State_DO_NOT_USE NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE("NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE", 1);

    void NodeIDAllocator_SendFSMState::BroadcastGlobalTransition(NodeIDAllocator_SendFSMContext& context)
    {
        Default(context);
        return;
    }

    void NodeIDAllocator_SendFSMState::BroadcastLocalTransition(NodeIDAllocator_SendFSMContext& context)
    {
        Default(context);
        return;
    }

    void NodeIDAllocator_SendFSMState::ReceiveTransition(NodeIDAllocator_SendFSMContext& context)
    {
        Default(context);
        return;
    }

    void NodeIDAllocator_SendFSMState::RequestNodeIDTransition(NodeIDAllocator_SendFSMContext& context)
    {
        Default(context);
        return;
    }

    void NodeIDAllocator_SendFSMState::SendTransition(NodeIDAllocator_SendFSMContext& context)
    {
        Default(context);
        return;
    }

    void NodeIDAllocator_SendFSMState::Default(NodeIDAllocator_SendFSMContext& context)
    {
        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "TRANSITION   : Default"
                << std::endl;
        }

        throw (
            TransitionUndefinedException(
                context.getState().getName(),
                context.getTransition()));

        return;
    }

    void NodeIDAllocator_SendFSM_SM_Internally_Generated_State_DO_NOT_USE::BroadcastGlobalTransition(NodeIDAllocator_SendFSMContext& context)
    {

        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "LEAVING STATE   : NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE"
            << std::endl;
        }

        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "ENTER TRANSITION: NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE::BroadcastGlobalTransition()"
                << std::endl;
        }

        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "EXIT TRANSITION : NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE::BroadcastGlobalTransition()"
                << std::endl;
        }


        return;
    }

    void NodeIDAllocator_SendFSM_SM_Internally_Generated_State_DO_NOT_USE::BroadcastLocalTransition(NodeIDAllocator_SendFSMContext& context)
    {

        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "LEAVING STATE   : NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE"
            << std::endl;
        }

        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "ENTER TRANSITION: NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE::BroadcastLocalTransition()"
                << std::endl;
        }

        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "EXIT TRANSITION : NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE::BroadcastLocalTransition()"
                << std::endl;
        }


        return;
    }

    void NodeIDAllocator_SendFSM_SM_Internally_Generated_State_DO_NOT_USE::ReceiveTransition(NodeIDAllocator_SendFSMContext& context)
    {

        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "LEAVING STATE   : NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE"
            << std::endl;
        }

        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "ENTER TRANSITION: NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE::ReceiveTransition()"
                << std::endl;
        }

        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "EXIT TRANSITION : NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE::ReceiveTransition()"
                << std::endl;
        }


        return;
    }

    void NodeIDAllocator_SendFSM_SM_Internally_Generated_State_DO_NOT_USE::RequestNodeIDTransition(NodeIDAllocator_SendFSMContext& context)
    {

        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "LEAVING STATE   : NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE"
            << std::endl;
        }

        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "ENTER TRANSITION: NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE::RequestNodeIDTransition()"
                << std::endl;
        }

        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "EXIT TRANSITION : NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE::RequestNodeIDTransition()"
                << std::endl;
        }


        return;
    }

    void NodeIDAllocator_SendFSM_SM_Internally_Generated_State_DO_NOT_USE::SendTransition(NodeIDAllocator_SendFSMContext& context)
    {

        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "LEAVING STATE   : NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE"
            << std::endl;
        }

        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "ENTER TRANSITION: NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE::SendTransition()"
                << std::endl;
        }

        if (context.getDebugFlag() == true)
        {
            std::ostream& str = context.getDebugStream();

            str << "EXIT TRANSITION : NodeIDAllocator_SendFSM_SM::Internally_Generated_State_DO_NOT_USE::SendTransition()"
                << std::endl;
        }


        return;
    }
}

/*
 * Local variables:
 *  buffer-read-only: t
 * End:
 */
