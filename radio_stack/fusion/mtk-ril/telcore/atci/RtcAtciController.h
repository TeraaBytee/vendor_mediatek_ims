/*
 * Copyright (C) 2021 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __RTC_ATCI_CONTROLLER_H__
#define __RTC_ATCI_CONTROLLER_H__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "RfxController.h"
#include "utils/Condition.h"
#include "utils/Mutex.h"

using ::android::Condition;
using ::android::Mutex;

/*****************************************************************************
 * Class RtcAtciController
 *****************************************************************************/
class RtcAtciController : public RfxController {
    RFX_DECLARE_CLASS(RtcAtciController);

public:
    RtcAtciController() {}
    virtual ~RtcAtciController() {}

// Override
protected:
    virtual void onInit();
    virtual bool onHandleAtciRequest(const sp<RfxMessage>& message);
    virtual bool onHandleAtciResponse(const sp<RfxMessage>& message);

private:
    static const char *LOG_TAG_ATCI;
    static const char *ENABLE_URC_PROP;
};

#endif /* __RTC_ATCI_CONTROLLER_H__ */
