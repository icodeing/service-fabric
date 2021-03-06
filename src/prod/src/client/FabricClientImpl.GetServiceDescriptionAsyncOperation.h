// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#pragma once

namespace Client
{
    using namespace Naming;

    class FabricClientImpl::GetServiceDescriptionAsyncOperation : public FabricClientImpl::ClientAsyncOperationBase
    {
    public:
        GetServiceDescriptionAsyncOperation(
            __in FabricClientImpl &client,
            __in Common::NamingUri const &associatedName,
            __in Transport::FabricActivityHeader && activityId,
            __in Common::TimeSpan const timeout,
            __in Common::AsyncCallback const& callback,
            __in Common::AsyncOperationSPtr const& parent,
            __in_opt Common::ErrorCode && passThroughError = Common::ErrorCode::Success());

        static Common::ErrorCode EndGetServiceGroupDescription(
            Common::AsyncOperationSPtr const & asyncOperation,
            __out Naming::ServiceGroupDescriptor &result);

        static Common::ErrorCode EndGetServiceDescription(
            Common::AsyncOperationSPtr const & asyncOperation,
            __out Naming::PartitionedServiceDescriptor &result);

    protected:
        void OnStartOperation(Common::AsyncOperationSPtr const & thisSPtr);

    private:

        void OnGetServiceDescriptionComplete(Common::AsyncOperationSPtr const& thisSPtr, bool);

        Common::NamingUri associatedName_;
        Naming::PartitionedServiceDescriptor description_;
    };
}
