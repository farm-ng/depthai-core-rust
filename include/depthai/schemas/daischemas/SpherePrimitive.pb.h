// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: daischemas/SpherePrimitive.proto
// Protobuf C++ Version: 4.25.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_daischemas_2fSpherePrimitive_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_daischemas_2fSpherePrimitive_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4025000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4025001 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
#include "daischemas/Color.pb.h"
#include "daischemas/Pose.pb.h"
#include "daischemas/Vector3.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_daischemas_2fSpherePrimitive_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_daischemas_2fSpherePrimitive_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_daischemas_2fSpherePrimitive_2eproto;
namespace dai {
namespace schemas {
class SpherePrimitive;
struct SpherePrimitiveDefaultTypeInternal;
extern SpherePrimitiveDefaultTypeInternal _SpherePrimitive_default_instance_;
}  // namespace schemas
}  // namespace dai
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace dai {
namespace schemas {

// ===================================================================


// -------------------------------------------------------------------

class SpherePrimitive final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:dai.schemas.SpherePrimitive) */ {
 public:
  inline SpherePrimitive() : SpherePrimitive(nullptr) {}
  ~SpherePrimitive() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR SpherePrimitive(::google::protobuf::internal::ConstantInitialized);

  inline SpherePrimitive(const SpherePrimitive& from)
      : SpherePrimitive(nullptr, from) {}
  SpherePrimitive(SpherePrimitive&& from) noexcept
    : SpherePrimitive() {
    *this = ::std::move(from);
  }

  inline SpherePrimitive& operator=(const SpherePrimitive& from) {
    CopyFrom(from);
    return *this;
  }
  inline SpherePrimitive& operator=(SpherePrimitive&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const SpherePrimitive& default_instance() {
    return *internal_default_instance();
  }
  static inline const SpherePrimitive* internal_default_instance() {
    return reinterpret_cast<const SpherePrimitive*>(
               &_SpherePrimitive_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SpherePrimitive& a, SpherePrimitive& b) {
    a.Swap(&b);
  }
  inline void Swap(SpherePrimitive* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SpherePrimitive* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  SpherePrimitive* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<SpherePrimitive>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const SpherePrimitive& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const SpherePrimitive& from) {
    SpherePrimitive::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(SpherePrimitive* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "dai.schemas.SpherePrimitive";
  }
  protected:
  explicit SpherePrimitive(::google::protobuf::Arena* arena);
  SpherePrimitive(::google::protobuf::Arena* arena, const SpherePrimitive& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPoseFieldNumber = 1,
    kSizeFieldNumber = 2,
    kColorFieldNumber = 3,
  };
  // .dai.schemas.Pose pose = 1;
  bool has_pose() const;
  void clear_pose() ;
  const ::dai::schemas::Pose& pose() const;
  PROTOBUF_NODISCARD ::dai::schemas::Pose* release_pose();
  ::dai::schemas::Pose* mutable_pose();
  void set_allocated_pose(::dai::schemas::Pose* value);
  void unsafe_arena_set_allocated_pose(::dai::schemas::Pose* value);
  ::dai::schemas::Pose* unsafe_arena_release_pose();

  private:
  const ::dai::schemas::Pose& _internal_pose() const;
  ::dai::schemas::Pose* _internal_mutable_pose();

  public:
  // .dai.schemas.Vector3 size = 2;
  bool has_size() const;
  void clear_size() ;
  const ::dai::schemas::Vector3& size() const;
  PROTOBUF_NODISCARD ::dai::schemas::Vector3* release_size();
  ::dai::schemas::Vector3* mutable_size();
  void set_allocated_size(::dai::schemas::Vector3* value);
  void unsafe_arena_set_allocated_size(::dai::schemas::Vector3* value);
  ::dai::schemas::Vector3* unsafe_arena_release_size();

  private:
  const ::dai::schemas::Vector3& _internal_size() const;
  ::dai::schemas::Vector3* _internal_mutable_size();

  public:
  // .dai.schemas.Color color = 3;
  bool has_color() const;
  void clear_color() ;
  const ::dai::schemas::Color& color() const;
  PROTOBUF_NODISCARD ::dai::schemas::Color* release_color();
  ::dai::schemas::Color* mutable_color();
  void set_allocated_color(::dai::schemas::Color* value);
  void unsafe_arena_set_allocated_color(::dai::schemas::Color* value);
  ::dai::schemas::Color* unsafe_arena_release_color();

  private:
  const ::dai::schemas::Color& _internal_color() const;
  ::dai::schemas::Color* _internal_mutable_color();

  public:
  // @@protoc_insertion_point(class_scope:dai.schemas.SpherePrimitive)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 3, 3,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::dai::schemas::Pose* pose_;
    ::dai::schemas::Vector3* size_;
    ::dai::schemas::Color* color_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_daischemas_2fSpherePrimitive_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// SpherePrimitive

// .dai.schemas.Pose pose = 1;
inline bool SpherePrimitive::has_pose() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.pose_ != nullptr);
  return value;
}
inline const ::dai::schemas::Pose& SpherePrimitive::_internal_pose() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  const ::dai::schemas::Pose* p = _impl_.pose_;
  return p != nullptr ? *p : reinterpret_cast<const ::dai::schemas::Pose&>(::dai::schemas::_Pose_default_instance_);
}
inline const ::dai::schemas::Pose& SpherePrimitive::pose() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:dai.schemas.SpherePrimitive.pose)
  return _internal_pose();
}
inline void SpherePrimitive::unsafe_arena_set_allocated_pose(::dai::schemas::Pose* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.pose_);
  }
  _impl_.pose_ = reinterpret_cast<::dai::schemas::Pose*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:dai.schemas.SpherePrimitive.pose)
}
inline ::dai::schemas::Pose* SpherePrimitive::release_pose() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::dai::schemas::Pose* released = _impl_.pose_;
  _impl_.pose_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
  released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  if (GetArena() == nullptr) {
    delete old;
  }
#else   // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArena() != nullptr) {
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return released;
}
inline ::dai::schemas::Pose* SpherePrimitive::unsafe_arena_release_pose() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:dai.schemas.SpherePrimitive.pose)

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::dai::schemas::Pose* temp = _impl_.pose_;
  _impl_.pose_ = nullptr;
  return temp;
}
inline ::dai::schemas::Pose* SpherePrimitive::_internal_mutable_pose() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  if (_impl_.pose_ == nullptr) {
    auto* p = CreateMaybeMessage<::dai::schemas::Pose>(GetArena());
    _impl_.pose_ = reinterpret_cast<::dai::schemas::Pose*>(p);
  }
  return _impl_.pose_;
}
inline ::dai::schemas::Pose* SpherePrimitive::mutable_pose() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::dai::schemas::Pose* _msg = _internal_mutable_pose();
  // @@protoc_insertion_point(field_mutable:dai.schemas.SpherePrimitive.pose)
  return _msg;
}
inline void SpherePrimitive::set_allocated_pose(::dai::schemas::Pose* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.pose_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }

  _impl_.pose_ = reinterpret_cast<::dai::schemas::Pose*>(value);
  // @@protoc_insertion_point(field_set_allocated:dai.schemas.SpherePrimitive.pose)
}

// .dai.schemas.Vector3 size = 2;
inline bool SpherePrimitive::has_size() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.size_ != nullptr);
  return value;
}
inline const ::dai::schemas::Vector3& SpherePrimitive::_internal_size() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  const ::dai::schemas::Vector3* p = _impl_.size_;
  return p != nullptr ? *p : reinterpret_cast<const ::dai::schemas::Vector3&>(::dai::schemas::_Vector3_default_instance_);
}
inline const ::dai::schemas::Vector3& SpherePrimitive::size() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:dai.schemas.SpherePrimitive.size)
  return _internal_size();
}
inline void SpherePrimitive::unsafe_arena_set_allocated_size(::dai::schemas::Vector3* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.size_);
  }
  _impl_.size_ = reinterpret_cast<::dai::schemas::Vector3*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:dai.schemas.SpherePrimitive.size)
}
inline ::dai::schemas::Vector3* SpherePrimitive::release_size() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);

  _impl_._has_bits_[0] &= ~0x00000002u;
  ::dai::schemas::Vector3* released = _impl_.size_;
  _impl_.size_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
  released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  if (GetArena() == nullptr) {
    delete old;
  }
#else   // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArena() != nullptr) {
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return released;
}
inline ::dai::schemas::Vector3* SpherePrimitive::unsafe_arena_release_size() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:dai.schemas.SpherePrimitive.size)

  _impl_._has_bits_[0] &= ~0x00000002u;
  ::dai::schemas::Vector3* temp = _impl_.size_;
  _impl_.size_ = nullptr;
  return temp;
}
inline ::dai::schemas::Vector3* SpherePrimitive::_internal_mutable_size() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  if (_impl_.size_ == nullptr) {
    auto* p = CreateMaybeMessage<::dai::schemas::Vector3>(GetArena());
    _impl_.size_ = reinterpret_cast<::dai::schemas::Vector3*>(p);
  }
  return _impl_.size_;
}
inline ::dai::schemas::Vector3* SpherePrimitive::mutable_size() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::dai::schemas::Vector3* _msg = _internal_mutable_size();
  // @@protoc_insertion_point(field_mutable:dai.schemas.SpherePrimitive.size)
  return _msg;
}
inline void SpherePrimitive::set_allocated_size(::dai::schemas::Vector3* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.size_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }

  _impl_.size_ = reinterpret_cast<::dai::schemas::Vector3*>(value);
  // @@protoc_insertion_point(field_set_allocated:dai.schemas.SpherePrimitive.size)
}

// .dai.schemas.Color color = 3;
inline bool SpherePrimitive::has_color() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.color_ != nullptr);
  return value;
}
inline const ::dai::schemas::Color& SpherePrimitive::_internal_color() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  const ::dai::schemas::Color* p = _impl_.color_;
  return p != nullptr ? *p : reinterpret_cast<const ::dai::schemas::Color&>(::dai::schemas::_Color_default_instance_);
}
inline const ::dai::schemas::Color& SpherePrimitive::color() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:dai.schemas.SpherePrimitive.color)
  return _internal_color();
}
inline void SpherePrimitive::unsafe_arena_set_allocated_color(::dai::schemas::Color* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.color_);
  }
  _impl_.color_ = reinterpret_cast<::dai::schemas::Color*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:dai.schemas.SpherePrimitive.color)
}
inline ::dai::schemas::Color* SpherePrimitive::release_color() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);

  _impl_._has_bits_[0] &= ~0x00000004u;
  ::dai::schemas::Color* released = _impl_.color_;
  _impl_.color_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
  released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  if (GetArena() == nullptr) {
    delete old;
  }
#else   // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArena() != nullptr) {
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return released;
}
inline ::dai::schemas::Color* SpherePrimitive::unsafe_arena_release_color() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:dai.schemas.SpherePrimitive.color)

  _impl_._has_bits_[0] &= ~0x00000004u;
  ::dai::schemas::Color* temp = _impl_.color_;
  _impl_.color_ = nullptr;
  return temp;
}
inline ::dai::schemas::Color* SpherePrimitive::_internal_mutable_color() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000004u;
  if (_impl_.color_ == nullptr) {
    auto* p = CreateMaybeMessage<::dai::schemas::Color>(GetArena());
    _impl_.color_ = reinterpret_cast<::dai::schemas::Color*>(p);
  }
  return _impl_.color_;
}
inline ::dai::schemas::Color* SpherePrimitive::mutable_color() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::dai::schemas::Color* _msg = _internal_mutable_color();
  // @@protoc_insertion_point(field_mutable:dai.schemas.SpherePrimitive.color)
  return _msg;
}
inline void SpherePrimitive::set_allocated_color(::dai::schemas::Color* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.color_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }

  _impl_.color_ = reinterpret_cast<::dai::schemas::Color*>(value);
  // @@protoc_insertion_point(field_set_allocated:dai.schemas.SpherePrimitive.color)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace schemas
}  // namespace dai


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_daischemas_2fSpherePrimitive_2eproto_2epb_2eh
