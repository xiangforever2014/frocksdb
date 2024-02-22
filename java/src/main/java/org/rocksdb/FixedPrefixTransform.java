// Copyright (c) 2011-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under both the GPLv2 (found in the
//  COPYING file in the root directory) and Apache 2.0 License
//  (found in the LICENSE.Apache file in the root directory).

package org.rocksdb;

/**
 * Fixed Prefix Transform
 */
public class FixedPrefixTransform extends SliceTransform {

  /**
   * Create a new FixedPrefixTransform.
   *
   * @param prefixLen The length of the prefix
   */
  public FixedPrefixTransform(final long prefixLen) {
    super(newFixedPrefixTransform(prefixLen));
  }

  private native static long newFixedPrefixTransform(final long prefixLen);
  @Override protected final native void disposeInternal(final long handle);
}
