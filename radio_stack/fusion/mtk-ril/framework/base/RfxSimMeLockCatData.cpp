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

#include "RfxSimMeLockCatData.h"
#include <telephony/mtk_ril.h>

RFX_IMPLEMENT_DATA_CLASS(RfxSimMeLockCatData);

RfxSimMeLockCatData::RfxSimMeLockCatData(void *_data, int _length) : RfxBaseData(_data, _length) {
    if (_data != NULL) {
        RIL_SimMeLockCatInfo *pSimMeLockInfo = (RIL_SimMeLockCatInfo*)_data;
        RIL_SimMeLockCatInfo *pData = (RIL_SimMeLockCatInfo *)calloc(1,
                sizeof(RIL_SimMeLockCatInfo));
        RFX_ASSERT(pData != NULL);

        pData->catagory = pSimMeLockInfo->catagory;
        pData->state = pSimMeLockInfo->state;
        pData->retry_cnt = pSimMeLockInfo->retry_cnt;
        pData->autolock_cnt = pSimMeLockInfo->autolock_cnt;
        pData->num_set = pSimMeLockInfo->num_set;
        pData->total_set = pSimMeLockInfo->total_set;
        pData->key_state = pSimMeLockInfo->key_state;

        m_data = (void*)pData;
        m_length = _length;
    }
}

RfxSimMeLockCatData::~RfxSimMeLockCatData() {
    if (m_data != NULL) {
        RIL_SimMeLockCatInfo *pData = (RIL_SimMeLockCatInfo*)m_data;

        // free memory
        free(m_data);
        m_data = NULL;
    }
}
