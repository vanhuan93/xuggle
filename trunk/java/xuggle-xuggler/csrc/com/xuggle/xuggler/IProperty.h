/*
 * Copyright (c) 2008-2009 by Xuggle Inc. All rights reserved.
 *
 * It is REQUESTED BUT NOT REQUIRED if you use this library, that you let
 * us know by sending e-mail to info@xuggle.com telling us briefly how you're
 * using the library and what you like or don't like about it.
 *
 * This library is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free Software
 * Foundation; either version 2.1 of the License, or (at your option) any later
 * version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along
 * with this library; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef IPROPERTY_H_
#define IPROPERTY_H_

#include <com/xuggle/xuggler/Xuggler.h>
#include <com/xuggle/ferry/RefCounted.h>
namespace com { namespace xuggle { namespace xuggler {
  /**
   * Represents attributes properties can have on objects in Xuggler.
   */
  class VS_API_XUGGLER IProperty : public com::xuggle::ferry::RefCounted
  {
  public:
    /**
     * The different type of options that are supported by Xuggler.
     * 
     * Well, actually by FFMPEG, but you get the idea.
     */
    typedef enum {
      PROPERTY_FLAGS,
      PROPERTY_INT,
      PROPERTY_INT64,
      PROPERTY_DOUBLE,
      PROPERTY_FLOAT,
      PROPERTY_STRING,
      PROPERTY_RATIONAL,
      PROPERTY_BINARY,
      PROPERTY_CONST=128,
      PROPERTY_UNKNOWN=-1,
    } Type;
    
    typedef enum {
      FLAG_ENCODING_PARAM=1,
      FLAG_DECODING_PARAM=2,
      FLAG_METADATA=4,
      FLAG_AUDIO_PARAM=8,
      FLAG_VIDEO_PARAM=16,
      FLAG_SUBTITLE_PARAM=32,
    } Flags;
    
    /**
     * Get the name for this property.
     * 
     * @return the name.
     */
    virtual const char *getName()=0;
    
    /**
     * Get the (English) help string for this property.
     * 
     * @return the help string
     */
    virtual const char *getHelp()=0;
    
    /**
     * Get any sub-unit this option or constant belongs to.
     * 
     * @return the unit, or null if none.
     */
    virtual const char *getUnit()=0;
    
    /**
     * Get the underlying native type of this property.
     * 
     * @return the type
     */
    virtual Type getType()=0;
    
    /**
     * Get any set flags (a bitmask) for this option.
     * 
     * @return the flags
     */
    virtual int32_t getFlags()=0;

    /**
     * Get the default setting this flag would have it not set.
     * 
     * @return the default
     */
    virtual int64_t getDefault()=0;
    
    /**
     * Get the default setting this flag would have it not set.
     * 
     * @return the default
     */
    virtual double getDefaultAsDouble()=0;
    
    /**
     * If this IProperty is of the type {@link Type#PROPERTY_FLAGS}, this method will
     * tell you how many different flag settings it takes.
     * 
     * @return Number of flag settings, or <0 if not a FLAGS value
     */
    virtual int32_t getNumFlagSettings()=0;
    
    /**
     * If this IProperty is of the type {@link Type#PROPERTY_FLAGS}, this method will
     * give you another IProperty representing a constant setting for that flag.
     * 
     * @param position The position number for the flag;  Must be in range 0 <= position <= #getNumFlagSettings().
     * 
     * @return An IProperty object for the flag setting, or null if not available.
     */
    virtual IProperty *getFlagConstant(int32_t position)=0;

    /**
     * If this IProperty is of the type {@link Type#PROPERTY_FLAGS}, this method will
     * give you another IProperty representing a constant setting for that flag.
     * 
     * @param name The name of the constant.
     * 
     * @return An IProperty object for the flag setting, or null if not available.
     */
    virtual IProperty *getFlagConstant(const char *name)=0;

  protected:
    IProperty();
    virtual ~IProperty();
    
  };

}}}
#endif /* IPROPERTY_H_ */