/*############################################################################
  # Copyright 2016 Intel Corporation
  #
  # Licensed under the Apache License, Version 2.0 (the "License");
  # you may not use this file except in compliance with the License.
  # You may obtain a copy of the License at
  #
  #     http://www.apache.org/licenses/LICENSE-2.0
  #
  # Unless required by applicable law or agreed to in writing, software
  # distributed under the License is distributed on an "AS IS" BASIS,
  # WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  # See the License for the specific language governing permissions and
  # limitations under the License.
  ############################################################################*/

/*!
 * \file
 * \brief Member C++ wrapper implementation.
 */

#include "epid/member/unittests/member-testhelper.h"

#include <cstdio>
#include <string>

MemberCtxObj::MemberCtxObj(GroupPubKey const& pub_key, PrivKey const& priv_key,
                           BitSupplier rnd_func, void* rnd_param)
    : ctx_(nullptr) {
  auto sts = EpidMemberCreate(&pub_key, &priv_key, nullptr, rnd_func, rnd_param,
                              &ctx_);
  if (kEpidNoErr != sts) {
    printf("%s(%d): %s\n", __FILE__, __LINE__, "test defect:");
    throw std::logic_error(std::string("Failed to call: ") +
                           "EpidMemberCreate()");
  }
}

MemberCtxObj::MemberCtxObj(GroupPubKey const& pub_key, PrivKey const& priv_key,
                           MemberPrecomp const& precomp, BitSupplier rnd_func,
                           void* rnd_param)
    : ctx_(nullptr) {
  auto sts = EpidMemberCreate(&pub_key, &priv_key, &precomp, rnd_func,
                              rnd_param, &ctx_);
  if (kEpidNoErr != sts) {
    printf("%s(%d): %s\n", __FILE__, __LINE__, "test defect:");
    throw std::logic_error(std::string("Failed to call: ") +
                           "EpidMemberCreate()");
  }
}

MemberCtxObj::~MemberCtxObj() { EpidMemberDelete(&ctx_); }

MemberCtx* MemberCtxObj::ctx() const { return ctx_; }

MemberCtxObj::operator MemberCtx*() const { return ctx_; }

MemberCtxObj::operator const MemberCtx*() const { return ctx_; }

/// Arbitrary test data were generated based on Intel(R) EPID 2.0 parameters
const GroupPubKey EpidMemberTest::group_public_key = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x01},  // group id
    {{{{0xb3, 0x6f, 0xff, 0x81, 0xe2, 0x1b, 0x17, 0xeb, 0x3d, 0x75, 0x3d, 0x61,
        0x7e, 0x27, 0xb0, 0xcb, 0xd0, 0x6d, 0x8f, 0x9d, 0x64, 0xce, 0xe3, 0xce,
        0x43, 0x4c, 0x62, 0xfd, 0xb5, 0x80, 0xe0, 0x99}}},
     {{{0x3a, 0x07, 0x56, 0x80, 0xe0, 0x88, 0x59, 0xa4, 0xfd, 0xb5, 0xb7, 0x9d,
        0xe9, 0x4d, 0xae, 0x9c, 0xee, 0x3d, 0x66, 0x42, 0x82, 0x45, 0x7e, 0x7f,
        0xd8, 0x69, 0x3e, 0xa1, 0x74, 0xf4, 0x59, 0xee}}}},  // h1
    {{{{0xd2, 0x74, 0x2e, 0x9f, 0x63, 0xc2, 0x51, 0x8e, 0xd5, 0xdb, 0xca, 0x1c,
        0x54, 0x74, 0x10, 0x7b, 0xdc, 0x99, 0xed, 0x42, 0xd5, 0x5b, 0xa7, 0x04,
        0x29, 0x66, 0x61, 0x63, 0xbc, 0xdd, 0x7f, 0xe1}}},
     {{{0x76, 0x5d, 0xc0, 0x6e, 0xe3, 0x14, 0xac, 0x72, 0x48, 0x12, 0x0a, 0xa6,
        0xe8, 0x5b, 0x08, 0x7b, 0xda, 0x3f, 0x51, 0x7d, 0xde, 0x4c, 0xea, 0xcb,
        0x93, 0xa5, 0x6e, 0xcc, 0xe7, 0x8e, 0x10, 0x84}}}},  // h2
    {{{{{0xbd, 0x19, 0x5a, 0x95, 0xe2, 0x0f, 0xca, 0x1c, 0x50, 0x71, 0x94, 0x51,
         0x40, 0x1b, 0xa5, 0xb6, 0x78, 0x87, 0x53, 0xf6, 0x6a, 0x95, 0xca, 0xc6,
         0x8d, 0xcd, 0x36, 0x88, 0x7, 0x28, 0xe8, 0x96}}},
      {{{0xca, 0x78, 0x11, 0x5b, 0xb8, 0x6a, 0xe7, 0xe5, 0xa6, 0x65, 0x7a, 0x68,
         0x15, 0xd7, 0x75, 0xf8, 0x24, 0x14, 0xcf, 0xd1, 0x0f, 0x6c, 0x56, 0xf5,
         0x22, 0xd9, 0xfd, 0xe0, 0xe2, 0xf4, 0xb3, 0xa1}}}},
     {{{{0x90, 0x21, 0xa7, 0xe0, 0xe8, 0xb3, 0xc7, 0x25, 0xbc, 0x07, 0x72, 0x30,
         0x5d, 0xee, 0xf5, 0x6a, 0x89, 0x88, 0x46, 0xdd, 0x89, 0xc2, 0x39, 0x9c,
         0x0a, 0x3b, 0x58, 0x96, 0x57, 0xe4, 0xf3, 0x3c}}},
      {{{0x79, 0x51, 0x69, 0x36, 0x1b, 0xb6, 0xf7, 0x05, 0x5d, 0x0a, 0x88, 0xdb,
         0x1f, 0x3d, 0xea, 0xa2, 0xba, 0x6b, 0xf0, 0xda, 0x8e, 0x25, 0xc6, 0xad,
         0x83, 0x7d, 0x3e, 0x31, 0xee, 0x11, 0x40, 0xa9}}}}}  // w
};

const PrivKey EpidMemberTest::member_private_key = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x01},  // group id
    {{{{0x46, 0xc9, 0x69, 0xee, 0xf4, 0x68, 0xe1, 0x5f, 0xac, 0xbf, 0xdd, 0x77,
        0xeb, 0x4c, 0xaf, 0x8a, 0x87, 0x68, 0x3f, 0x4e, 0xda, 0xf2, 0x96, 0xec,
        0x57, 0x08, 0x90, 0xe8, 0x19, 0x62, 0x54, 0xdb}}},
     {{{0x1e, 0x52, 0x23, 0x16, 0x91, 0xe4, 0xa8, 0x1d, 0x9a, 0x1b, 0x8a, 0xad,
        0x0a, 0xcf, 0x36, 0x4f, 0xae, 0x43, 0xde, 0x62, 0xff, 0xa6, 0x4b, 0xa8,
        0x16, 0x24, 0x98, 0x80, 0x82, 0x80, 0x37, 0x77}}}},  // A
    {0x0a, 0x30, 0xae, 0x43, 0xa1, 0xe0, 0xd7, 0xdf, 0x10, 0x5e, 0xaf, 0xd8,
     0x5a, 0x61, 0x10, 0x86, 0xd0, 0x9d, 0xb9, 0xe4, 0x46, 0xdd, 0xb7, 0x1b,
     0x00, 0x14, 0x7c, 0x6b, 0x13, 0x72, 0xc3, 0x77},  // x
    {0x48, 0x40, 0xb5, 0x6c, 0x6d, 0x47, 0x09, 0x0b, 0x05, 0xd6, 0x43, 0x56,
     0xe0, 0x7c, 0xc6, 0x8e, 0xa1, 0x65, 0x67, 0xfd, 0xa7, 0x07, 0x87, 0x9b,
     0x36, 0x2d, 0x41, 0x35, 0x63, 0x61, 0x31, 0xc7}  // f
};

const MemberPrecomp EpidMemberTest::member_precomp = {
    {0xd8, 0x14, 0xba, 0x4b, 0x44, 0x03, 0x55, 0x6c, 0xf6, 0x42, 0xe8, 0xf0,
     0x4c, 0xb5, 0xe7, 0xd4, 0xa2, 0xa3, 0x69, 0x47, 0xf5, 0xd4, 0xc8, 0xe9,
     0xc5, 0x5a, 0x39, 0xb5, 0x55, 0xa5, 0xd3, 0xfb, 0xf3, 0x85, 0x5a, 0x0d,
     0xd5, 0xee, 0xde, 0xf4, 0xa8, 0xb1, 0x8b, 0xcf, 0xa9, 0x0d, 0x29, 0xbf,
     0x86, 0x27, 0x9c, 0x1f, 0x96, 0xed, 0xd8, 0x44, 0x01, 0x35, 0x1a, 0xce,
     0xfd, 0x4e, 0x6f, 0xa1, 0x66, 0x0d, 0x59, 0x08, 0x6d, 0xa2, 0xe4, 0x99,
     0x83, 0xdc, 0x39, 0x28, 0xb7, 0x1c, 0x1a, 0x33, 0xad, 0xca, 0x5c, 0x35,
     0x26, 0x1f, 0xab, 0xba, 0x0d, 0x53, 0xaf, 0xe0, 0x72, 0x14, 0xc5, 0xa7,
     0x2e, 0x58, 0x26, 0xc9, 0x8e, 0xfa, 0x6f, 0x62, 0xfc, 0xf0, 0x08, 0x3e,
     0xa3, 0x11, 0x3a, 0xf0, 0xb8, 0x3b, 0x2d, 0x3e, 0xec, 0xd5, 0xbc, 0xf2,
     0x05, 0x68, 0xf4, 0x40, 0xce, 0x2c, 0x8f, 0xdd, 0xa4, 0xe5, 0xe1, 0xb5,
     0xbe, 0xbd, 0x3e, 0xd4, 0xf6, 0x9a, 0xb3, 0x37, 0x24, 0x0d, 0xea, 0x13,
     0xd7, 0x1f, 0xa2, 0x75, 0x68, 0xa1, 0xbe, 0x2c, 0x01, 0x42, 0x2a, 0xae,
     0x6f, 0xae, 0x7a, 0x72, 0x3a, 0x11, 0x03, 0x58, 0x02, 0x0d, 0xf0, 0xb0,
     0xd9, 0x6f, 0xb1, 0xe4, 0xf2, 0x70, 0xb8, 0xff, 0x22, 0x56, 0x7c, 0xb3,
     0x80, 0xfd, 0xdf, 0xe5, 0xab, 0xcc, 0x18, 0x7a, 0xfd, 0x91, 0xd0, 0xb0,
     0x63, 0x40, 0xd4, 0x71, 0xfa, 0x03, 0xf5, 0xf1, 0x26, 0xe1, 0xa5, 0x5a,
     0xd9, 0x6d, 0xf5, 0x5a, 0x7b, 0x2a, 0x3a, 0xfe, 0x94, 0x9e, 0x74, 0x41,
     0x79, 0x49, 0x7e, 0x48, 0x1d, 0x58, 0x5e, 0xf6, 0x98, 0xa3, 0x6e, 0x61,
     0x8e, 0x9f, 0x1f, 0xcd, 0x15, 0x01, 0x16, 0xa5, 0xe0, 0xab, 0xd6, 0xd6,
     0x1f, 0x1c, 0xf5, 0x81, 0x76, 0xc1, 0xec, 0x10, 0xc2, 0xcc, 0x68, 0x59,
     0x4d, 0x47, 0xef, 0x4b, 0x7f, 0xd8, 0x78, 0x9c, 0xfe, 0x9a, 0x86, 0x7e,
     0x0c, 0xfd, 0x3e, 0x0a, 0x7a, 0x72, 0x8b, 0x14, 0x5f, 0xe6, 0x5f, 0x19,
     0xa3, 0x0a, 0x1b, 0x71, 0xdc, 0xd2, 0xae, 0x35, 0xc3, 0x11, 0xa5, 0xd3,
     0xea, 0xe1, 0xa9, 0xe7, 0x70, 0x0c, 0x7a, 0x39, 0x56, 0x3c, 0xe4, 0xe7,
     0xf9, 0xb6, 0xf1, 0x15, 0x40, 0xab, 0xb6, 0xc4, 0xad, 0xbd, 0xf4, 0xcc,
     0x13, 0xb7, 0xa8, 0xb6, 0x92, 0x1e, 0x72, 0x27, 0xa7, 0xff, 0xd9, 0xea,
     0x2f, 0x91, 0x96, 0x22, 0xd2, 0xc4, 0x4d, 0x80, 0xdc, 0x47, 0x66, 0x87,
     0xcc, 0xcf, 0xc5, 0x64, 0xf7, 0xb2, 0x34, 0xed, 0xd5, 0x44, 0x44, 0xcc,
     0x57, 0x41, 0xc7, 0x92, 0xb7, 0x5c, 0x12, 0xf7, 0x81, 0xf2, 0x92, 0x35,
     0x3e, 0x4b, 0xdf, 0xf8, 0xda, 0x68, 0xac, 0x30, 0xe3, 0xdd, 0x9e, 0x22,
     0xaa, 0x6d, 0x77, 0xdd, 0xac, 0xd9, 0x11, 0x6e, 0xfb, 0x1a, 0x88,
     0xb3},  // e12
    {
        0x07, 0x3f, 0x9d, 0x47, 0x82, 0xb8, 0x3d, 0x6a, 0xe0, 0x36, 0xab, 0xa6,
        0xfa, 0xe6, 0xd2, 0x1c, 0xc8, 0xb2, 0xd0, 0x01, 0xd4, 0x96, 0xdc, 0x2e,
        0xf8, 0x19, 0xdc, 0x70, 0x1b, 0xf9, 0x73, 0x0c, 0x2b, 0xc2, 0xe2, 0x1d,
        0x85, 0x53, 0x81, 0x51, 0xfb, 0xca, 0x16, 0x86, 0xd4, 0x4e, 0xfd, 0x1a,
        0x59, 0xe3, 0x97, 0xc4, 0x7f, 0x99, 0xd8, 0x66, 0x08, 0xa1, 0xe4, 0x9f,
        0xbb, 0x3a, 0xce, 0xa5, 0x23, 0x9c, 0x83, 0x13, 0xc5, 0xc8, 0xf2, 0x16,
        0x1e, 0xe8, 0xe6, 0xc5, 0x36, 0x57, 0x2c, 0xdf, 0x73, 0xb4, 0xe2, 0xb2,
        0xcb, 0xeb, 0xbb, 0xf7, 0x45, 0xd1, 0x44, 0xbd, 0x6e, 0x92, 0x95, 0x00,
        0xe5, 0x89, 0xb5, 0x91, 0x78, 0xc7, 0x44, 0xb1, 0x2f, 0x37, 0xdf, 0xfb,
        0xe7, 0x8a, 0x44, 0x3f, 0x3d, 0x06, 0x5f, 0x5b, 0x1c, 0x5f, 0xce, 0x11,
        0x05, 0x35, 0x3c, 0xad, 0x92, 0x7e, 0x79, 0xb8, 0xff, 0x28, 0x05, 0xe4,
        0x04, 0x2c, 0xb6, 0x1d, 0x22, 0xab, 0x36, 0x00, 0x5f, 0x74, 0xf1, 0xe3,
        0xf6, 0xa6, 0x68, 0xe6, 0x7b, 0x25, 0xb8, 0xcf, 0x19, 0xb0, 0x1a, 0xdd,
        0x0f, 0xad, 0x63, 0x73, 0x62, 0x1b, 0xe7, 0x94, 0x5d, 0xbf, 0x3d, 0xf1,
        0xf9, 0x8e, 0xab, 0x59, 0xe5, 0xd1, 0x7c, 0x62, 0xdd, 0xbc, 0x40, 0x07,
        0x70, 0x5b, 0x13, 0xf6, 0x12, 0x09, 0xb4, 0x0d, 0x3e, 0xab, 0x8b, 0x70,
        0x60, 0x1d, 0xd4, 0x61, 0x37, 0x28, 0x98, 0x3e, 0x7e, 0xdc, 0xfd, 0xd2,
        0xc0, 0x2f, 0x4b, 0x71, 0x31, 0x34, 0xd7, 0x69, 0x41, 0x5e, 0xaa, 0x72,
        0xe4, 0xdf, 0xeb, 0xfe, 0x8d, 0xcd, 0x68, 0xfc, 0x68, 0x55, 0xbe, 0x32,
        0x7d, 0x24, 0xc5, 0x07, 0x0f, 0xa8, 0xbd, 0x5a, 0xfe, 0xe7, 0xec, 0xdb,
        0xfd, 0x19, 0xc8, 0xa9, 0x20, 0xa2, 0x7f, 0x6c, 0xa6, 0x62, 0xec, 0xed,
        0x9b, 0x79, 0xbf, 0x9c, 0x0e, 0x31, 0x0b, 0x25, 0x2f, 0xd3, 0xcc, 0xa0,
        0xdd, 0xb2, 0xf2, 0x69, 0x26, 0x85, 0x21, 0x06, 0x94, 0x56, 0x5f, 0x59,
        0x5c, 0xf5, 0xb7, 0x82, 0xce, 0x0f, 0xdd, 0x40, 0xdb, 0x83, 0xac, 0x3c,
        0x41, 0xa0, 0x1b, 0xb1, 0xaf, 0xda, 0x55, 0xbf, 0x6b, 0x1a, 0xef, 0xe6,
        0x90, 0xe7, 0xaa, 0x0f, 0x04, 0x3c, 0x9f, 0x5b, 0xb7, 0xcd, 0x98, 0xa8,
        0x9e, 0xff, 0x54, 0x26, 0xc8, 0xd5, 0x5c, 0x30, 0x5e, 0xa2, 0x99, 0x8e,
        0x34, 0xd5, 0x98, 0x9f, 0xcd, 0x57, 0xd1, 0x4d, 0x1d, 0xee, 0x01, 0x5d,
        0x5a, 0x6d, 0xb2, 0xf1, 0xcf, 0x4b, 0xc0, 0x21, 0x23, 0x96, 0x05, 0xf9,
        0xc9, 0x66, 0xe5, 0x25, 0x9d, 0xa3, 0x8e, 0x78, 0x43, 0x19, 0xc1, 0x7f,
        0x7b, 0xef, 0xf5, 0xed, 0x00, 0xb7, 0x45, 0x1f, 0x4e, 0xa9, 0xfa, 0xe3,
        0xff, 0x54, 0xf2, 0x21, 0x73, 0xf8, 0x6b, 0xa1, 0xc7, 0x31, 0x4d, 0x6a,
    },  // e22
    {
        0x49, 0x0d, 0x0f, 0x2a, 0x5c, 0x6a, 0x3b, 0xad, 0x71, 0xc9, 0x22, 0x49,
        0xe8, 0x08, 0xdd, 0xba, 0x79, 0x57, 0xb7, 0xc7, 0x61, 0xe4, 0xdb, 0x84,
        0x68, 0x57, 0xb9, 0x30, 0x83, 0xa4, 0xdc, 0xef, 0x70, 0x93, 0x28, 0xe2,
        0x6f, 0xb9, 0xbc, 0x15, 0x28, 0x3a, 0x30, 0xbd, 0x96, 0x83, 0xdb, 0xf2,
        0x9d, 0x1e, 0xc7, 0x64, 0x6d, 0x2e, 0x7c, 0xa2, 0xf3, 0xaa, 0x2f, 0x4b,
        0x6d, 0x86, 0x9e, 0x48, 0x20, 0x29, 0x4b, 0x1f, 0x8d, 0xc2, 0x93, 0xc3,
        0x55, 0x25, 0x8e, 0xb0, 0x8a, 0x7e, 0x64, 0x45, 0x3f, 0xf4, 0x1d, 0x16,
        0x4c, 0x88, 0x2d, 0x54, 0xbe, 0xa8, 0x67, 0x70, 0x81, 0xc5, 0xb9, 0x5c,
        0x16, 0x00, 0xef, 0x78, 0xf6, 0x4d, 0x6a, 0xeb, 0xfd, 0xa2, 0x0d, 0x52,
        0x86, 0xf3, 0x04, 0x4b, 0xd8, 0xf0, 0x7d, 0x50, 0x8b, 0xad, 0xc0, 0x37,
        0xdb, 0x38, 0xf2, 0x7d, 0x1f, 0x8b, 0x13, 0x83, 0x7b, 0xcc, 0xe8, 0x25,
        0xfe, 0xfa, 0x0c, 0x02, 0x05, 0x2e, 0x75, 0x12, 0xa1, 0x0a, 0x89, 0xab,
        0xf1, 0xb2, 0x08, 0x47, 0x9a, 0xea, 0xef, 0x1d, 0xa4, 0x9f, 0xde, 0x89,
        0x47, 0x3e, 0x7c, 0x5e, 0x4a, 0x40, 0xdc, 0xec, 0xc5, 0x1b, 0x7e, 0x33,
        0x0a, 0x19, 0x69, 0x27, 0xa6, 0xcc, 0x25, 0xfc, 0xf9, 0xeb, 0xbd, 0xb7,
        0x8a, 0xdb, 0x45, 0x5f, 0x9d, 0x9e, 0x01, 0xde, 0x3d, 0x91, 0x10, 0x99,
        0x13, 0xbf, 0xc0, 0xfa, 0x9d, 0xd4, 0x0f, 0xb3, 0x09, 0xf3, 0xa1, 0xae,
        0x68, 0xe1, 0x1b, 0x48, 0x85, 0x9f, 0x81, 0x66, 0x91, 0xe2, 0xf0, 0x7b,
        0x29, 0xdb, 0x8f, 0x5d, 0x99, 0xa9, 0xd3, 0x39, 0x30, 0xd9, 0x1b, 0x94,
        0x2a, 0x1c, 0x5c, 0xe9, 0xc0, 0x3f, 0x6e, 0xb2, 0x27, 0xbe, 0x74, 0x7a,
        0xca, 0xe1, 0x0f, 0x6a, 0x43, 0x2e, 0x98, 0x65, 0xaf, 0x7f, 0x6e, 0x5a,
        0x55, 0x98, 0xc1, 0x58, 0x29, 0xb3, 0x86, 0x54, 0x0f, 0x57, 0x91, 0x89,
        0x29, 0xb1, 0x98, 0x79, 0xcc, 0x95, 0x39, 0xd0, 0xab, 0xe0, 0x9f, 0xf3,
        0xda, 0xf9, 0x5e, 0xd9, 0x34, 0xbb, 0x72, 0xda, 0xe5, 0x72, 0xd3, 0xf8,
        0x9b, 0xf9, 0x14, 0x84, 0x48, 0x81, 0x54, 0x4f, 0xe6, 0x2b, 0x80, 0xc8,
        0xc1, 0x79, 0xfe, 0x83, 0xff, 0x76, 0xa3, 0x6d, 0xfe, 0x37, 0x78, 0xc5,
        0x30, 0x7a, 0x50, 0xe2, 0x5d, 0x12, 0xdc, 0x72, 0xe9, 0x58, 0x7c, 0x07,
        0x4f, 0xff, 0x15, 0x8a, 0x97, 0x3b, 0xcb, 0x60, 0xfa, 0x4e, 0xde, 0x8c,
        0x80, 0x3a, 0x8b, 0x0b, 0xc6, 0x1d, 0xa3, 0xce, 0x6a, 0xb3, 0x50, 0x69,
        0x03, 0x96, 0xca, 0xc0, 0xb6, 0x94, 0x6f, 0x8f, 0xab, 0x6f, 0x5b, 0x00,
        0x2a, 0x1d, 0x90, 0xa7, 0x81, 0xc6, 0x15, 0x77, 0x79, 0xf3, 0x36, 0x23,
        0xd1, 0x46, 0x25, 0x58, 0x6f, 0x7b, 0x22, 0xac, 0x4c, 0x7a, 0xf3, 0x9f,
    },  // e2w
    {
        0x8d, 0x71, 0xe2, 0xb0, 0x73, 0x2f, 0x4a, 0xba, 0x64, 0xe8, 0x7a, 0x12,
        0xaf, 0xe4, 0x4f, 0xdb, 0x6b, 0x3e, 0x38, 0x07, 0x0c, 0x79, 0x22, 0x48,
        0x1b, 0x9d, 0x33, 0x53, 0x5c, 0x75, 0x3b, 0x40, 0x5e, 0x18, 0xd1, 0x92,
        0x4a, 0xd1, 0x82, 0x1c, 0xc7, 0x3a, 0xf7, 0x7e, 0x32, 0x19, 0x99, 0x5d,
        0x01, 0x0e, 0xb0, 0xf2, 0x8f, 0x80, 0xc6, 0xb9, 0xeb, 0x1f, 0x9e, 0xae,
        0x9e, 0xe0, 0x99, 0xfd, 0xe8, 0x93, 0x11, 0x61, 0x7d, 0xc2, 0x49, 0xdb,
        0xa8, 0x73, 0xa4, 0xa9, 0x33, 0xe2, 0x04, 0xd1, 0x7d, 0x8b, 0xe1, 0xd6,
        0x2b, 0x10, 0x6c, 0x79, 0x02, 0xbf, 0xfc, 0x53, 0x03, 0xa9, 0xbc, 0x30,
        0x4d, 0x4d, 0xf4, 0x32, 0xce, 0x9a, 0x4a, 0xfa, 0xd6, 0x7f, 0x26, 0x17,
        0xc5, 0xf6, 0xed, 0xe4, 0xcc, 0xb9, 0x79, 0xe2, 0xa8, 0x86, 0xbb, 0xd7,
        0xfb, 0x05, 0xd2, 0x81, 0xbe, 0x07, 0x1c, 0x47, 0x48, 0x4f, 0x6d, 0x6b,
        0x52, 0x42, 0xe4, 0xc6, 0x20, 0x46, 0xa3, 0xae, 0x5b, 0x55, 0x55, 0xfe,
        0x4a, 0xad, 0xf2, 0x32, 0x07, 0x0f, 0x91, 0xa9, 0xe5, 0xd3, 0x86, 0x08,
        0x73, 0x93, 0xc7, 0x1e, 0x6b, 0xcd, 0x69, 0xd0, 0xfb, 0xc1, 0x74, 0xc2,
        0xb8, 0x90, 0xc8, 0xf8, 0x93, 0xbf, 0x08, 0x0f, 0x15, 0x19, 0x26, 0x71,
        0x4a, 0x9e, 0xdf, 0xdf, 0xca, 0x6f, 0xca, 0xfd, 0x67, 0xec, 0x4d, 0x21,
        0x5b, 0x99, 0xbd, 0x4b, 0x79, 0x22, 0x2d, 0xe4, 0x24, 0x72, 0x88, 0x93,
        0xce, 0xe6, 0x7f, 0xef, 0x35, 0x83, 0x67, 0x39, 0xb9, 0x34, 0x80, 0x64,
        0x0a, 0xf4, 0xff, 0x42, 0x9d, 0xee, 0xda, 0xb8, 0xd3, 0xdc, 0x1d, 0x0d,
        0x9f, 0x45, 0xe9, 0xbe, 0xf4, 0x3e, 0xa6, 0x58, 0x8b, 0xf0, 0xfd, 0x01,
        0x73, 0x63, 0xd0, 0xc6, 0x9d, 0xb9, 0x32, 0xd1, 0x91, 0xfe, 0xb1, 0xf5,
        0x4b, 0x48, 0xb4, 0x46, 0xae, 0x61, 0xd7, 0x90, 0xfe, 0x86, 0x74, 0x68,
        0xee, 0x78, 0x86, 0x65, 0x99, 0x6d, 0x7b, 0xf0, 0x17, 0x1a, 0x4c, 0xb0,
        0x37, 0x73, 0xdc, 0x38, 0x41, 0xfa, 0x02, 0xd2, 0x13, 0x8f, 0x71, 0xb4,
        0x0a, 0x72, 0x70, 0x0f, 0xe1, 0x2c, 0x9a, 0xa9, 0x51, 0xfa, 0xb2, 0xbf,
        0x84, 0xf2, 0xa6, 0xfb, 0xc3, 0x83, 0x16, 0x7e, 0x27, 0xec, 0x06, 0x5d,
        0x64, 0x79, 0xe7, 0x42, 0x30, 0xf8, 0x2d, 0xbc, 0x0f, 0x07, 0x8b, 0xf2,
        0x99, 0xda, 0x91, 0x4c, 0x65, 0xcf, 0x7f, 0x57, 0x2d, 0x2f, 0x67, 0xe7,
        0xfb, 0x75, 0xe9, 0xb2, 0xa3, 0x72, 0x60, 0x88, 0x2b, 0x14, 0x31, 0x62,
        0xbc, 0x45, 0x59, 0x5c, 0x58, 0x39, 0xb3, 0x4a, 0xeb, 0xb9, 0x18, 0x24,
        0x05, 0xcb, 0xda, 0xd3, 0x5e, 0x54, 0xba, 0xda, 0xfd, 0xfc, 0xa0, 0x02,
        0xb3, 0xde, 0x52, 0x3e, 0xc0, 0xd0, 0xb8, 0x19, 0x85, 0x1b, 0x7b, 0xe3,
    }  // ea2
};
const PreComputedSignature EpidMemberTest::precomputed_signatures[2] = {
    {
        {{{{0x5c, 0x1b, 0x75, 0x1c, 0xc7, 0x2c, 0xf7, 0x4a, 0x97, 0x43, 0xf2,
            0x1a, 0x70, 0x80, 0x90, 0x61, 0xf5, 0x9e, 0x9b, 0x43, 0x92, 0x2f,
            0x05, 0x28, 0xcc, 0x4c, 0xb4, 0xb2, 0x80, 0x15, 0x58, 0x14}}},
         {{{
             0x3f, 0x7f, 0xd0, 0x95, 0x08, 0x98, 0x0b, 0xae, 0x88, 0xf8, 0x2c,
             0x18, 0x8b, 0x72, 0x50, 0x95, 0x78, 0x41, 0xae, 0x4e, 0x6e, 0xea,
             0x3d, 0xa6, 0x23, 0x91, 0x4a, 0x02, 0x5d, 0x3f, 0x97, 0xd9,
         }}}},  // B
        {{{{0xb0, 0xdb, 0x88, 0x23, 0x18, 0x95, 0xba, 0x60, 0x72, 0x43, 0xb4,
            0x57, 0xbd, 0x20, 0xd2, 0x28, 0x97, 0xf7, 0x3a, 0x50, 0x06, 0xc5,
            0x89, 0xc9, 0x9f, 0x7a, 0x2a, 0x80, 0x91, 0xee, 0x7a, 0xf8}}},
         {{{0x70, 0xf3, 0x95, 0x12, 0xe4, 0x95, 0xca, 0x19, 0x43, 0x1a, 0x5d,
            0x47, 0x33, 0x71, 0x69, 0xfb, 0x14, 0x5f, 0xbd, 0x3f, 0xb2, 0x72,
            0x22, 0x3f, 0x63, 0xc3, 0xe9, 0x7c, 0x18, 0x82, 0x88,
            0x03}}}},  // K
        {{{{0x75, 0x39, 0x21, 0x47, 0x04, 0xfd, 0xb7, 0x71, 0xb2, 0xf5, 0xa9,
            0x83, 0x7f, 0x27, 0x1d, 0x8f, 0xff, 0x07, 0x3c, 0xfb, 0xe9, 0x0d,
            0x14, 0x9c, 0xa6, 0xee, 0x06, 0x1e, 0x3d, 0xd3, 0xfb, 0x92}}},
         {{{0x51, 0x64, 0x11, 0x6d, 0x22, 0xc7, 0xed, 0x67, 0x21, 0xfe, 0x76,
            0x27, 0xf9, 0x43, 0x43, 0x64, 0x11, 0x01, 0x63, 0xc8, 0xda, 0x42,
            0x4e, 0x02, 0xe7, 0xf2, 0xb8, 0xa4, 0x16, 0x5b, 0x39,
            0xc2}}}},  // T
        {{{{0x60, 0x25, 0xeb, 0xe8, 0x51, 0xd5, 0xe0, 0xf3, 0xcc, 0xb2, 0xc2,
            0xe3, 0xd7, 0x5c, 0x84, 0x41, 0x57, 0x2b, 0x5b, 0x00, 0xac, 0x1d,
            0x14, 0x89, 0xba, 0xb3, 0x34, 0xf0, 0x8a, 0xd4, 0x72, 0x5e}}},
         {{{0x93, 0xb7, 0xed, 0x03, 0xdd, 0xc7, 0xc9, 0xfa, 0x2c, 0x32, 0x84,
            0x40, 0xd4, 0xa2, 0x74, 0x76, 0x02, 0xef, 0x0c, 0xc6, 0xe4, 0xc2,
            0x9f, 0xd7, 0x18, 0x96, 0xdc, 0x97, 0x22, 0x4e, 0xbf,
            0xfc}}}},  // R1
        {
            0xe4, 0x5f, 0x6c, 0x74, 0x0b, 0xb7, 0x26, 0x59, 0x62, 0x5e, 0x69,
            0x71, 0x01, 0xa8, 0x32, 0xc1, 0xa7, 0xae, 0x32, 0x9e, 0xc2, 0xaf,
            0x9a, 0x55, 0x6c, 0x71, 0x37, 0x80, 0xc7, 0xe1, 0x8b, 0x1c, 0xa1,
            0x0c, 0xce, 0x60, 0x10, 0x18, 0x14, 0xe9, 0x66, 0x84, 0xe0, 0x52,
            0x9d, 0xee, 0x42, 0x0f, 0x47, 0xba, 0xcc, 0xc1, 0xea, 0xeb, 0x93,
            0x18, 0x04, 0x39, 0x7e, 0x36, 0x59, 0x73, 0xd3, 0xf8, 0xa4, 0x67,
            0x64, 0x6a, 0x24, 0x00, 0xd3, 0x4b, 0x0b, 0x17, 0x7f, 0xc6, 0xca,
            0x1a, 0xe3, 0x29, 0x4a, 0x4d, 0x23, 0x7d, 0x02, 0xa4, 0xd3, 0x26,
            0xed, 0xe6, 0x4d, 0xb7, 0xc6, 0x2d, 0x70, 0x85, 0xf0, 0xa4, 0x54,
            0x7f, 0xe9, 0x6e, 0x17, 0xb3, 0x36, 0xa4, 0x30, 0xfc, 0xca, 0x80,
            0x8c, 0x8b, 0x17, 0x6f, 0xe8, 0x22, 0x76, 0x27, 0xd7, 0x42, 0xd5,
            0x14, 0x27, 0x9a, 0x8d, 0x0c, 0x9c, 0x43, 0x7e, 0x41, 0x7a, 0x73,
            0xd9, 0xee, 0xef, 0xc7, 0x42, 0x77, 0xbe, 0x27, 0xa3, 0x8f, 0xa1,
            0x77, 0xaf, 0xdc, 0xa2, 0xfc, 0xf1, 0x3d, 0xd6, 0x00, 0xf3, 0x9c,
            0x43, 0xe9, 0xff, 0xc7, 0x9f, 0x5f, 0x6c, 0xa9, 0x16, 0x47, 0x73,
            0xbb, 0x31, 0x45, 0xb1, 0xcf, 0x7f, 0x39, 0xdd, 0x27, 0x78, 0x03,
            0x45, 0x24, 0x67, 0x08, 0x04, 0xf1, 0xbf, 0xfa, 0x7f, 0xe2, 0x2f,
            0x1f, 0x2c, 0x68, 0xfe, 0x4e, 0x0a, 0xcf, 0xd7, 0xf5, 0x0b, 0xd2,
            0xe2, 0x55, 0x54, 0x15, 0xa6, 0x3d, 0x0c, 0xc3, 0x49, 0xcd, 0x86,
            0xa7, 0x51, 0x12, 0x08, 0x4c, 0xf6, 0x05, 0xbc, 0xdc, 0xb1, 0x22,
            0xe4, 0x92, 0x33, 0x92, 0x8f, 0x6b, 0xee, 0x74, 0x96, 0xaf, 0x7c,
            0x47, 0x65, 0xb6, 0x4d, 0xd8, 0xd4, 0x21, 0xa8, 0xfa, 0xf9, 0x03,
            0xc7, 0xf4, 0x82, 0xde, 0x0a, 0xd9, 0x4c, 0x92, 0xfc, 0x48, 0x65,
            0x1a, 0x4c, 0xb9, 0xf9, 0x91, 0x9e, 0xf4, 0x88, 0x9e, 0x83, 0xa9,
            0x3a, 0x2e, 0x50, 0x94, 0xde, 0xb0, 0x24, 0xf3, 0x9b, 0xa0, 0x9e,
            0x0c, 0x49, 0xb2, 0xe2, 0x53, 0xfc, 0x52, 0x9b, 0x4b, 0x3b, 0x53,
            0xdf, 0xfe, 0x76, 0x99, 0x19, 0x90, 0xb8, 0xf2, 0x8c, 0xda, 0x57,
            0xfc, 0x35, 0xf6, 0xeb, 0xb4, 0x3c, 0xde, 0xff, 0x75, 0xf2, 0x50,
            0x27, 0x20, 0x42, 0x33, 0xd8, 0x6c, 0x5f, 0xba, 0x3d, 0xed, 0x90,
            0x77, 0xbc, 0x97, 0x10, 0xe0, 0x37, 0x21, 0x9e, 0x37, 0xf4, 0x89,
            0x34, 0x7c, 0x4a, 0x27, 0x8b, 0x58, 0x99, 0x83, 0x0a, 0xa7, 0x80,
            0x11, 0xc4, 0x88, 0xf2, 0xbb, 0xc0, 0x99, 0x9f, 0x6f, 0x60, 0x12,
            0x2d, 0x52, 0x20, 0x3a, 0xc0, 0x50, 0x75, 0x97, 0xc9, 0xdb, 0x01,
            0x3d, 0x05, 0x21, 0x3a, 0x16, 0x67, 0x0f, 0x7b, 0x51, 0x4a, 0x33,
            0x93, 0x53, 0x78, 0xd0, 0xb4, 0x91, 0xfc, 0x32, 0x49, 0x5e,
        },  // R2
        {0x02, 0x5c, 0x15, 0x7e, 0x0f, 0x00, 0x82, 0x32, 0x45, 0xcf, 0x91, 0xd3,
         0x64, 0x5f, 0xf6, 0x0a, 0x83, 0x83, 0xc6, 0x3c, 0x0a, 0x68, 0x2c, 0x1e,
         0x96, 0x4b, 0xfa, 0xde, 0x06, 0xfe, 0x1a, 0x73},  // a
        {0xea, 0x9d, 0xe1, 0x57, 0x32, 0x2e, 0x74, 0xd5, 0xbe, 0x49, 0xc4, 0xc8,
         0x23, 0x7d, 0x93, 0x74, 0x05, 0xee, 0xc2, 0x3d, 0xec, 0xd5, 0xbd, 0x4c,
         0x2f, 0x1d, 0x77, 0x88, 0x2b, 0x81, 0x5e, 0xc4},  // b
        {0x98, 0x43, 0xdc, 0x08, 0x7b, 0x99, 0xff, 0x4a, 0x38, 0xbd, 0x5f, 0xe9,
         0xfc, 0xb9, 0x40, 0x3c, 0x31, 0x9b, 0x57, 0x7e, 0xff, 0x1c, 0x80, 0x92,
         0x79, 0x97, 0x3d, 0xa9, 0xbb, 0x70, 0xe7, 0x4b},  // rx
        {0x85, 0x09, 0xac, 0xad, 0xcb, 0x5f, 0x24, 0x36, 0x21, 0x9e, 0xc7, 0x3a,
         0x2b, 0xf6, 0x63, 0xe7, 0x0d, 0xef, 0x3f, 0x4d, 0x40, 0x94, 0x49, 0x7b,
         0x2c, 0x89, 0xfe, 0xdc, 0xe7, 0x5b, 0xc5, 0x72},  // rf
        {0x0d, 0x6b, 0x41, 0x78, 0x87, 0xb7, 0x90, 0x17, 0x5c, 0xe1, 0x9d, 0xcb,
         0x5d, 0x87, 0x69, 0xe6, 0xdd, 0xc0, 0xef, 0xbb, 0x3f, 0x4d, 0xaf, 0xec,
         0x3a, 0x66, 0x66, 0xb3, 0x51, 0x49, 0xb8, 0xae},  // ra
        {0xaa, 0x42, 0x63, 0x36, 0x47, 0xe3, 0x9d, 0x5e, 0x7f, 0xcd, 0x07, 0xee,
         0x26, 0xdc, 0xaf, 0x88, 0xf1, 0x9b, 0xae, 0xa4, 0x7c, 0xff, 0x2e, 0x4f,
         0x7b, 0x6d, 0xb1, 0x42, 0x50, 0x9d, 0x89, 0x39}  // rb
    },
    {
        {{{{0x10, 0x11, 0x7a, 0x7a, 0xbd, 0xe9, 0x4f, 0x96, 0xd7, 0x1e, 0x53,
            0x05, 0x8d, 0x69, 0xb1, 0xdb, 0x3e, 0xf1, 0x3c, 0x24, 0xe2, 0x83,
            0x06, 0x4b, 0xd6, 0xd9, 0xc6, 0x24, 0xf4, 0x7f, 0x67, 0x2c}}},
         {{{0x1a, 0xaf, 0x95, 0xfa, 0x7e, 0x59, 0xd2, 0x93, 0x39, 0x09, 0xae,
            0x0b, 0xc3, 0xe8, 0xe5, 0xf7, 0x36, 0xe7, 0x06, 0xbf, 0xe3, 0xd2,
            0x20, 0xbf, 0xd2, 0x31, 0x3f, 0xc1, 0x15, 0x61, 0x61,
            0x03}}}},  // B
        {{{{0xcc, 0x9e, 0x80, 0x5e, 0x0c, 0x32, 0x44, 0x70, 0xe0, 0x44, 0x27,
            0x7a, 0x01, 0xee, 0x51, 0x19, 0xa1, 0x4d, 0x0a, 0x24, 0x8b, 0xa2,
            0xf8, 0xa3, 0x26, 0x56, 0x8c, 0x70, 0xe1, 0xa1, 0x83, 0x70}}},
         {{{0x4d, 0xf0, 0x73, 0x6f, 0xf4, 0x62, 0xc4, 0x30, 0x3e, 0xde, 0xff,
            0xc0, 0x93, 0x92, 0xa4, 0x03, 0x6f, 0x84, 0x3a, 0x3c, 0x34, 0x25,
            0x83, 0xb5, 0x2b, 0x90, 0x95, 0x6b, 0x24, 0x82, 0x6e,
            0xe6}}}},  // K
        {{{{0xc6, 0x4c, 0xc8, 0x9d, 0xdc, 0x63, 0x46, 0x5b, 0xab, 0x79, 0xea,
            0x49, 0x76, 0x47, 0x68, 0xe6, 0x2e, 0x7d, 0x0b, 0x49, 0xc0, 0x29,
            0xe4, 0xc8, 0x84, 0xb5, 0x04, 0x2d, 0x15, 0xaa, 0x0d, 0xd4}}},
         {{{0x71, 0x43, 0xd0, 0x24, 0x3e, 0x00, 0xf4, 0x94, 0xad, 0x1e, 0x1e,
            0x32, 0xea, 0x21, 0x4d, 0x83, 0xae, 0x63, 0x3c, 0x5a, 0xd4, 0xa5,
            0x79, 0x9b, 0x2c, 0xad, 0x03, 0x50, 0xb6, 0x57, 0x0a,
            0xbf}}}},  // T
        {{{{0xdd, 0x13, 0x14, 0x5a, 0x7d, 0x23, 0xc5, 0xf0, 0xcb, 0xa7, 0xd1,
            0x79, 0x7a, 0x59, 0x91, 0xf3, 0x8f, 0xb3, 0xff, 0x27, 0x52, 0x0e,
            0xe4, 0xc8, 0xb2, 0xe1, 0xc5, 0x29, 0x16, 0x2e, 0x0f, 0xcf}}},
         {{{0xcd, 0xb1, 0xed, 0x9a, 0xf3, 0x8a, 0xdd, 0x97, 0xe3, 0x58, 0xd8,
            0x66, 0xc0, 0xb9, 0xe6, 0x5e, 0x86, 0x6b, 0xfc, 0xde, 0x25, 0x2b,
            0x3c, 0x97, 0x4e, 0xc9, 0x26, 0x12, 0xf7, 0xde, 0xa6,
            0x88}}}},  // R1
        {0x75, 0x5e, 0x75, 0xe8, 0x80, 0xa3, 0x3b, 0x5d, 0xb7, 0xf1, 0x93, 0x4e,
         0x55, 0x6a, 0x14, 0x24, 0x8c, 0x74, 0xcd, 0x58, 0x25, 0xf8, 0x26, 0x6f,
         0x21, 0xc1, 0x1f, 0xb1, 0x7a, 0xc5, 0x48, 0x6b, 0x01, 0x4e, 0xa0, 0xa7,
         0xac, 0x55, 0x5b, 0x68, 0xba, 0x69, 0x17, 0xb0, 0x1e, 0x4a, 0x88, 0x70,
         0xbc, 0xb8, 0x12, 0xd7, 0x3d, 0x1b, 0xb4, 0xee, 0x79, 0xdb, 0xa1, 0x31,
         0xfb, 0x09, 0x3e, 0x89, 0xf6, 0x92, 0x0a, 0x81, 0x6a, 0xde, 0xe6, 0xb9,
         0x26, 0x9e, 0x5f, 0x2a, 0x52, 0xa2, 0x2e, 0x44, 0x0c, 0x15, 0xce, 0xbf,
         0x1f, 0xcf, 0x95, 0xe5, 0x17, 0x1c, 0xf3, 0xd2, 0x90, 0x04, 0xa4, 0xfa,
         0x0e, 0x92, 0x8b, 0xa4, 0xcd, 0x2b, 0xdf, 0x78, 0x71, 0x98, 0xd7, 0x9f,
         0xcd, 0xd1, 0x5e, 0x06, 0xdb, 0x6b, 0xdb, 0xff, 0x8d, 0xb4, 0x10, 0x73,
         0xc8, 0xf6, 0xb9, 0x42, 0x54, 0xc4, 0x6a, 0xc3, 0xbb, 0xdc, 0xec, 0x6d,
         0x2f, 0xec, 0xda, 0xb7, 0x74, 0x02, 0x59, 0xb9, 0xe0, 0x4c, 0xc5, 0x41,
         0x8a, 0x00, 0x2b, 0x10, 0x45, 0x9a, 0xc3, 0x77, 0x98, 0x66, 0xcf, 0xcb,
         0x44, 0xe7, 0x9a, 0x56, 0x40, 0xde, 0x74, 0x9b, 0x9f, 0x34, 0x9f, 0xc0,
         0x59, 0x28, 0x27, 0x3f, 0x90, 0xe0, 0xaa, 0xba, 0x0d, 0x13, 0x8a, 0xec,
         0x97, 0x2a, 0xef, 0xe7, 0xc9, 0x8f, 0xfa, 0xef, 0x14, 0x3a, 0xc2, 0x39,
         0xf6, 0x54, 0xab, 0x28, 0x15, 0x9f, 0x8d, 0x91, 0x49, 0x94, 0x27, 0x72,
         0x47, 0x97, 0x2a, 0x88, 0xb4, 0x95, 0xf4, 0xb7, 0xf3, 0x4d, 0xe3, 0xf0,
         0x53, 0x69, 0x58, 0xaf, 0xb7, 0x22, 0x52, 0x05, 0x9c, 0xac, 0x52, 0xbb,
         0x39, 0xc6, 0x6b, 0xfd, 0xfd, 0xdb, 0x1c, 0xf8, 0xa6, 0xce, 0xd6, 0xe6,
         0x4a, 0xd5, 0xb4, 0xcf, 0x68, 0x24, 0x79, 0xf6, 0xb0, 0xb8, 0x62, 0x37,
         0xc6, 0xa9, 0x14, 0x25, 0x07, 0xec, 0xde, 0x3a, 0x18, 0x13, 0xf9, 0x35,
         0x8d, 0xd7, 0x40, 0x34, 0x8c, 0xe9, 0x3f, 0x97, 0xe1, 0x6e, 0xcf, 0x9e,
         0xb0, 0x5d, 0x15, 0x5f, 0xd7, 0xd4, 0x92, 0x26, 0xa4, 0x87, 0x77, 0x47,
         0x95, 0x53, 0x78, 0x4b, 0x77, 0xd4, 0xb4, 0xd4, 0xad, 0xd2, 0xeb, 0xfb,
         0x70, 0x7b, 0xea, 0x6d, 0x88, 0x9b, 0xb6, 0xf9, 0x95, 0xa2, 0xae, 0x77,
         0xd3, 0x29, 0x43, 0xeb, 0x25, 0x09, 0x3c, 0x68, 0xc5, 0xba, 0x6f, 0x6e,
         0x19, 0x6a, 0x41, 0xb5, 0x02, 0x3f, 0x2e, 0xbe, 0x8e, 0xc4, 0x72, 0x47,
         0x65, 0x7d, 0x2a, 0xbb, 0x55, 0xea, 0x01, 0x2c, 0x24, 0x28, 0x1d, 0x90,
         0x63, 0xe5, 0x8e, 0x4f, 0xb7, 0x0e, 0x86, 0x09, 0x18, 0x5f, 0x1d, 0x69,
         0x72, 0x1a, 0xff, 0x25, 0xb2, 0x82, 0x19, 0x66, 0xbc, 0x68, 0x02, 0x07,
         0x02, 0x05, 0x07, 0x80, 0x88, 0xc9, 0x85, 0xf7, 0xa9, 0x32, 0x0a,
         0x48},  // R2
        {0xb2, 0x9f, 0x28, 0x17, 0xa9, 0x3b, 0x93, 0x5d, 0x84, 0xaa, 0xb9, 0xd2,
         0x61, 0x4c, 0xe4, 0x64, 0x79, 0x2b, 0xc2, 0x87, 0xe4, 0x7f, 0xe2, 0xd6,
         0xe7, 0x20, 0x7f, 0x3f, 0x65, 0x3d, 0x03, 0xa5},  // a
        {0xf2, 0xfa, 0x9f, 0x28, 0x8f, 0x1f, 0xd0, 0x6b, 0xa2, 0xe3, 0x37, 0xce,
         0x1c, 0x43, 0x82, 0x81, 0x18, 0x01, 0x75, 0x04, 0xf0, 0x2b, 0xb5, 0xb0,
         0x46, 0x5d, 0x44, 0x7f, 0xaa, 0xb3, 0x8a, 0xd2},  // b
        {0xf3, 0xe0, 0xab, 0x75, 0x37, 0x41, 0x61, 0x0d, 0xf5, 0x4a, 0x1f, 0xa6,
         0xee, 0xa5, 0xc6, 0x55, 0xd2, 0xa6, 0xce, 0x1c, 0x08, 0x64, 0x75, 0x22,
         0x15, 0x81, 0x45, 0x76, 0x21, 0x2c, 0x32, 0xca},  // rx
        {0x6e, 0xfc, 0x5c, 0x0a, 0x79, 0x3a, 0x5d, 0xca, 0xe6, 0xdc, 0x30, 0x12,
         0x96, 0x5a, 0x95, 0x3f, 0x8b, 0xa6, 0x86, 0x6d, 0x43, 0xf4, 0x4e, 0xfd,
         0x4f, 0xf2, 0x7a, 0x80, 0xa5, 0xcc, 0x05, 0x56},  // rf
        {0xcb, 0x58, 0xde, 0x49, 0xd7, 0x19, 0xfa, 0xbf, 0x5f, 0x82, 0x19, 0x0e,
         0x60, 0xb5, 0x0d, 0xde, 0xda, 0xb5, 0xf2, 0xb0, 0xcc, 0x2f, 0x65, 0x5e,
         0x71, 0x08, 0xd6, 0xb5, 0xd5, 0xbc, 0x67, 0xc1},  // ra
        {0xe0, 0x3a, 0x71, 0xa7, 0x86, 0x56, 0xea, 0xd0, 0x19, 0xce, 0xa9, 0x65,
         0xe8, 0x26, 0x11, 0x56, 0x5c, 0xcb, 0x04, 0x65, 0x36, 0xfd, 0xd9, 0x39,
         0x35, 0xfa, 0x78, 0xa5, 0xc2, 0x3c, 0x2e, 0x17}  // rb
    }};
const std::vector<uint8_t> EpidMemberTest::group_public_key_data_ikgf = {
#include "epid/common/testdata/ikgf/groupa/pubkey.inc"
};
const std::vector<uint8_t> EpidMemberTest::member_private_key_data_ikgf = {
#include "epid/common/testdata/ikgf/groupa/member0/mprivkey.inc"
};

const std::vector<uint8_t> EpidMemberTest::grp01_member0_sig_test1_sha256 = {
#include "epid/common/testdata/grp01/member0/sig_test1_sha256.inc"
};
const std::vector<uint8_t> EpidMemberTest::grp01_member0_sig_test1_sha384 = {
#include "epid/common/testdata/grp01/member0/sig_test1_sha384.inc"
};
const std::vector<uint8_t> EpidMemberTest::grp01_member0_sig_test1_sha512 = {
#include "epid/common/testdata/grp01/member0/sig_test1_sha512.inc"
};
const std::vector<uint8_t> EpidMemberTest::test1_msg = {'t', 'e', 's', 't',
                                                        '1'};
std::vector<uint8_t> EpidMemberTest::sig_rl_data = {
#include "epid/common/testdata/grp01/sigrl.inc"
};
std::vector<uint8_t> EpidMemberTest::sig_rl_5_entry_data = {
    // gid
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01,
    // version
    0x00, 0x00, 0x00, 0x00,
    // n2
    0x00, 0x00, 0x00, 0x05,
    // bk's
    0x9c, 0xa5, 0xe5, 0xae, 0x5f, 0xae, 0x51, 0x59, 0x33, 0x35, 0x27, 0xd, 0x8,
    0xb1, 0xbe, 0x5d, 0x69, 0x50, 0x84, 0xc5, 0xfe, 0xe2, 0x87, 0xea, 0x2e,
    0xef, 0xfa, 0xee, 0x67, 0xf2, 0xd8, 0x28, 0x56, 0x43, 0xc6, 0x94, 0x67,
    0xa6, 0x72, 0xf6, 0x41, 0x15, 0x4, 0x58, 0x42, 0x16, 0x88, 0x57, 0x9d, 0xc7,
    0x71, 0xd1, 0xc, 0x84, 0x13, 0xa, 0x90, 0x23, 0x18, 0x8, 0xad, 0x7d, 0xfe,
    0xf5, 0xc8, 0xae, 0xfc, 0x51, 0x40, 0xa7, 0xd1, 0x28, 0xc2, 0x89, 0xb2,
    0x6b, 0x4e, 0xb4, 0xc1, 0x55, 0x87, 0x98, 0xbd, 0x72, 0xf9, 0xcf, 0xd, 0x40,
    0x15, 0xee, 0x32, 0xc, 0xf3, 0x56, 0xc5, 0xc, 0x61, 0x9d, 0x4f, 0x7a, 0xb5,
    0x2b, 0x16, 0xa9, 0xa3, 0x97, 0x38, 0xe2, 0xdd, 0x3a, 0x33, 0xad, 0xf6,
    0x7b, 0x68, 0x8b, 0x68, 0xcf, 0xa3, 0xd3, 0x98, 0x37, 0xce, 0xec, 0xd1,
    0xa8, 0xc, 0x8b,

    0x71, 0x8a, 0xb5, 0x1, 0x7f, 0x7c, 0x92, 0x9a, 0xa2, 0xc9, 0x81, 0x10, 0xfe,
    0xbf, 0xc, 0x53, 0xa4, 0x43, 0xaf, 0x31, 0x74, 0x12, 0x25, 0x60, 0x3e, 0xc0,
    0x21, 0xe6, 0x63, 0x9a, 0xd2, 0x67, 0x2d, 0xb5, 0xd5, 0x82, 0xc4, 0x49,
    0x29, 0x51, 0x42, 0x8f, 0xe0, 0xe, 0xd1, 0x73, 0x27, 0xf5, 0x77, 0x16, 0x4,
    0x40, 0x8a, 0x0, 0xe, 0x3a, 0x5d, 0x37, 0x42, 0xd3, 0x8, 0x40, 0xbd, 0x69,
    0xf7, 0x5f, 0x74, 0x21, 0x50, 0xf4, 0xce, 0xfe, 0xd9, 0xdd, 0x97, 0x6c,
    0xa8, 0xa5, 0x60, 0x6b, 0xf8, 0x1b, 0xba, 0x2, 0xb2, 0xca, 0x5, 0x44, 0x9b,
    0xb1, 0x5e, 0x3a, 0xa4, 0x35, 0x7a, 0x51, 0xfa, 0xcf, 0xa4, 0x4, 0xe9, 0xf3,
    0xbf, 0x38, 0xd4, 0x24, 0x9, 0x52, 0xf3, 0x58, 0x3d, 0x9d, 0x4b, 0xb3, 0x37,
    0x4b, 0xec, 0x87, 0xe1, 0x64, 0x60, 0x3c, 0xb6, 0xf7, 0x7b, 0xff, 0x40,
    0x11,

    0x6e, 0x22, 0xaa, 0x10, 0x84, 0x58, 0x8b, 0xff, 0xd8, 0x37, 0x8, 0xa9, 0xe9,
    0xdb, 0xf6, 0x1f, 0x69, 0x10, 0x95, 0x6c, 0xbf, 0xd, 0x11, 0x48, 0x6f, 0x1b,
    0x3c, 0x62, 0x46, 0x13, 0x89, 0x13, 0x5f, 0xa1, 0x3, 0x62, 0xed, 0x62, 0xdf,
    0x3d, 0xbf, 0xcd, 0xb7, 0x41, 0x48, 0x81, 0x3, 0x9f, 0x54, 0xa, 0xe, 0xb3,
    0x35, 0xf9, 0xde, 0x24, 0xba, 0x6d, 0x4c, 0x7f, 0xfc, 0xc1, 0xb4, 0xce,
    0x6d, 0xa1, 0x73, 0x7c, 0xaa, 0xb, 0xad, 0x2, 0xd6, 0x37, 0x85, 0xe, 0xbb,
    0x48, 0x11, 0x38, 0xc4, 0xaa, 0x1b, 0xf, 0xcf, 0xc1, 0x9c, 0x26, 0xcc, 0x95,
    0xc2, 0x5b, 0x49, 0x9, 0x3d, 0xe9, 0x7d, 0xce, 0xc7, 0xa6, 0x4, 0x3e, 0x7c,
    0x9e, 0x28, 0xde, 0x8, 0x11, 0xe, 0x61, 0x3b, 0xc0, 0x9c, 0x6b, 0x58, 0x23,
    0xe6, 0x40, 0x7b, 0xbd, 0xb8, 0x72, 0xf, 0xe0, 0xee, 0xcf, 0xba, 0xb4,

    0xc4, 0xff, 0xaf, 0x48, 0x15, 0xda, 0x60, 0x40, 0xcc, 0xd7, 0xf2, 0x68,
    0xf7, 0xe2, 0x70, 0x12, 0x8d, 0x15, 0xa5, 0xb7, 0xe6, 0x4c, 0x23, 0xea,
    0x4d, 0x8a, 0x51, 0x6, 0x67, 0x3, 0x4c, 0x83, 0x6f, 0x28, 0x67, 0xcf, 0x63,
    0x46, 0x3e, 0x8a, 0x45, 0x9f, 0xed, 0x1a, 0xde, 0xa7, 0xad, 0xb2, 0x2b, 0xf,
    0x8b, 0xab, 0x7c, 0x70, 0xff, 0xc3, 0xa8, 0x6e, 0x8c, 0xaa, 0xb1, 0xf6,
    0x20, 0xe3, 0xb9, 0xf1, 0xc3, 0x3d, 0x5, 0x6a, 0x1e, 0x26, 0x2d, 0xf4, 0xd,
    0xe4, 0x53, 0x63, 0x67, 0x23, 0x48, 0xa8, 0x1, 0xa8, 0xee, 0xe1, 0x5f, 0x64,
    0xe3, 0x2c, 0x71, 0xe2, 0x10, 0x82, 0x0, 0x52, 0xd7, 0x74, 0x87, 0xff, 0x1c,
    0x0, 0x19, 0xe6, 0x4d, 0x15, 0x91, 0x6d, 0xf3, 0x38, 0x3b, 0xee, 0xf3, 0xd5,
    0xd1, 0xc7, 0x6d, 0xd9, 0x8e, 0x55, 0x70, 0x90, 0xb0, 0xb, 0x3c, 0x4a, 0x67,
    0x19,

    0x4f, 0x98, 0x92, 0xf9, 0x18, 0x38, 0xf5, 0xb4, 0xf7, 0x2f, 0xa7, 0x21,
    0x71, 0x52, 0x27, 0xd0, 0x57, 0x4f, 0x9c, 0x30, 0xe, 0xb2, 0x27, 0xce, 0xd7,
    0xb2, 0x9f, 0xc0, 0xf6, 0xc3, 0xb0, 0x7c, 0x40, 0x18, 0x75, 0x4a, 0xde,
    0xb0, 0x9f, 0x46, 0x8a, 0x5a, 0xeb, 0x4f, 0xcb, 0x5e, 0x60, 0xf5, 0xca,
    0xf4, 0x98, 0xaf, 0x62, 0x9b, 0x7e, 0x10, 0xda, 0xba, 0x2f, 0x47, 0x64,
    0xf2, 0xc0, 0x84, 0x19, 0x75, 0xe0, 0xe4, 0xff, 0x20, 0xda, 0x7d, 0xe5, 0xd,
    0xc8, 0xf8, 0xe3, 0x83, 0x61, 0x19, 0x17, 0xf1, 0xa9, 0x1b, 0xff, 0x39,
    0x79, 0x88, 0x1, 0xfb, 0xe7, 0x23, 0xd2, 0xac, 0xe0, 0x49, 0x12, 0x2a, 0x38,
    0xb4, 0x7c, 0xc2, 0x1b, 0x88, 0x5f, 0x68, 0x32, 0x11, 0xd9, 0xfd, 0xdc,
    0x65, 0x2, 0xb3, 0x74, 0x2c, 0x13, 0xf2, 0xd8, 0xf1, 0x45, 0xc5, 0xd1, 0xf4,
    0xa3, 0x38, 0x81, 0x92};
const std::vector<uint8_t> EpidMemberTest::kMsg0 = {'m', 's', 'g', '0'};
const std::vector<uint8_t> EpidMemberTest::kBsn0 = {'b', 's', 'n', '0'};
const std::vector<uint8_t> EpidMemberTest::kMsg1 = {'m', 's', 'g', '1'};
const std::vector<uint8_t> EpidMemberTest::kBsn1 = {'b', 's', 'n', '1'};

const GroupPubKey EpidMemberTest::kGrpXKey = {
#include "epid/common/testdata/grp_x/pubkey.inc"
};

const CompressedPrivKey EpidMemberTest::kGrpXMember9CompressedKey = {
#include "epid/common/testdata/grp_x/cmember9/cmpprivkey.inc"
};
const PrivKey EpidMemberTest::kGrpXMember9PrivKey = {
#include "epid/common/testdata/grp_x/cmember9/mprivkey.inc"
};

const GroupPubKey EpidMemberTest::kGrpYKey = {
#include "epid/common/testdata/grp_y/pubkey.inc"
};

const CompressedPrivKey EpidMemberTest::kGrpYMember9CompressedKey = {
#include "epid/common/testdata/grp_y/cmember9/cmpprivkey.inc"
};
