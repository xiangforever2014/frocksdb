// Copyright (c) 2011-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under both the GPLv2 (found in the
//  COPYING file in the root directory) and Apache 2.0 License
//  (found in the LICENSE.Apache file in the root directory).
//
// This file implements the "bridge" between Java and C++ for
// ROCKSDB_NAMESPACE::LRUCache.

#include <jni.h>

#include "rocksdb/slice_transform.h"
#include "include/org_rocksdb_FixedPrefixTransform.h"

/*
 * Class:     org_rocksdb_FixedPrefixTransform
 * Method:    newLRUCache
 * Signature: (JIZD)J
 */
jlong Java_org_rocksdb_FixedPrefixTransform_newFixedPrefixTransform(JNIEnv* /*env*/, jclass /*jcls*/,
                                            jlong jprefix_len) {
  auto* ptr_fixed_prefix_transfor = ROCKSDB_NAMESPACE::NewFixedPrefixTransform(
          static_cast<size_t>(jprefix_len)));
  return reinterpret_cast<jlong>(ptr_fixed_prefix_transfor);
}

/*
 * Class:     org_rocksdb_FixedPrefixTransform
 * Method:    disposeInternal
 * Signature: (J)V
 */
void Java_org_rocksdb_FixedPrefixTransform_disposeInternal(JNIEnv* /*env*/,
                                               jobject /*jobj*/,
                                               jlong jhandle) {
  auto* ptr_fixed_prefix_transform =
      reinterpret_cast<ROCKSDB_NAMESPACE::SliceTransform*>(jhandle);
  delete ptr_fixed_prefix_transform;  // delete ptr
}
