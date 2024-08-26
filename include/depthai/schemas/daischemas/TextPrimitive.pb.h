// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: daischemas/TextPrimitive.proto
// Protobuf C++ Version: 4.25.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_daischemas_2fTextPrimitive_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_daischemas_2fTextPrimitive_2eproto_2epb_2eh

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
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_daischemas_2fTextPrimitive_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_daischemas_2fTextPrimitive_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_daischemas_2fTextPrimitive_2eproto;
namespace dai {
namespace schemas {
class TextPrimitive;
struct TextPrimitiveDefaultTypeInternal;
extern TextPrimitiveDefaultTypeInternal _TextPrimitive_default_instance_;
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

class TextPrimitive final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:dai.schemas.TextPrimitive) */ {
 public:
  inline TextPrimitive() : TextPrimitive(nullptr) {}
  ~TextPrimitive() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR TextPrimitive(::google::protobuf::internal::ConstantInitialized);

  inline TextPrimitive(const TextPrimitive& from)
      : TextPrimitive(nullptr, from) {}
  TextPrimitive(TextPrimitive&& from) noexcept
    : TextPrimitive() {
    *this = ::std::move(from);
  }

  inline TextPrimitive& operator=(const TextPrimitive& from) {
    CopyFrom(from);
    return *this;
  }
  inline TextPrimitive& operator=(TextPrimitive&& from) noexcept {
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
  static const TextPrimitive& default_instance() {
    return *internal_default_instance();
  }
  static inline const TextPrimitive* internal_default_instance() {
    return reinterpret_cast<const TextPrimitive*>(
               &_TextPrimitive_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(TextPrimitive& a, TextPrimitive& b) {
    a.Swap(&b);
  }
  inline void Swap(TextPrimitive* other) {
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
  void UnsafeArenaSwap(TextPrimitive* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TextPrimitive* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<TextPrimitive>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const TextPrimitive& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const TextPrimitive& from) {
    TextPrimitive::MergeImpl(*this, from);
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
  void InternalSwap(TextPrimitive* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "dai.schemas.TextPrimitive";
  }
  protected:
  explicit TextPrimitive(::google::protobuf::Arena* arena);
  TextPrimitive(::google::protobuf::Arena* arena, const TextPrimitive& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTextFieldNumber = 6,
    kPoseFieldNumber = 1,
    kColorFieldNumber = 5,
    kFontSizeFieldNumber = 3,
    kBillboardFieldNumber = 2,
    kScaleInvariantFieldNumber = 4,
  };
  // string text = 6;
  void clear_text() ;
  const std::string& text() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_text(Arg_&& arg, Args_... args);
  std::string* mutable_text();
  PROTOBUF_NODISCARD std::string* release_text();
  void set_allocated_text(std::string* value);

  private:
  const std::string& _internal_text() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_text(
      const std::string& value);
  std::string* _internal_mutable_text();

  public:
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
  // .dai.schemas.Color color = 5;
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
  // double font_size = 3;
  void clear_font_size() ;
  double font_size() const;
  void set_font_size(double value);

  private:
  double _internal_font_size() const;
  void _internal_set_font_size(double value);

  public:
  // bool billboard = 2;
  void clear_billboard() ;
  bool billboard() const;
  void set_billboard(bool value);

  private:
  bool _internal_billboard() const;
  void _internal_set_billboard(bool value);

  public:
  // bool scale_invariant = 4;
  void clear_scale_invariant() ;
  bool scale_invariant() const;
  void set_scale_invariant(bool value);

  private:
  bool _internal_scale_invariant() const;
  void _internal_set_scale_invariant(bool value);

  public:
  // @@protoc_insertion_point(class_scope:dai.schemas.TextPrimitive)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      3, 6, 2,
      38, 2>
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
    ::google::protobuf::internal::ArenaStringPtr text_;
    ::dai::schemas::Pose* pose_;
    ::dai::schemas::Color* color_;
    double font_size_;
    bool billboard_;
    bool scale_invariant_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_daischemas_2fTextPrimitive_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// TextPrimitive

// .dai.schemas.Pose pose = 1;
inline bool TextPrimitive::has_pose() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.pose_ != nullptr);
  return value;
}
inline const ::dai::schemas::Pose& TextPrimitive::_internal_pose() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  const ::dai::schemas::Pose* p = _impl_.pose_;
  return p != nullptr ? *p : reinterpret_cast<const ::dai::schemas::Pose&>(::dai::schemas::_Pose_default_instance_);
}
inline const ::dai::schemas::Pose& TextPrimitive::pose() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:dai.schemas.TextPrimitive.pose)
  return _internal_pose();
}
inline void TextPrimitive::unsafe_arena_set_allocated_pose(::dai::schemas::Pose* value) {
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
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:dai.schemas.TextPrimitive.pose)
}
inline ::dai::schemas::Pose* TextPrimitive::release_pose() {
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
inline ::dai::schemas::Pose* TextPrimitive::unsafe_arena_release_pose() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:dai.schemas.TextPrimitive.pose)

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::dai::schemas::Pose* temp = _impl_.pose_;
  _impl_.pose_ = nullptr;
  return temp;
}
inline ::dai::schemas::Pose* TextPrimitive::_internal_mutable_pose() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  if (_impl_.pose_ == nullptr) {
    auto* p = CreateMaybeMessage<::dai::schemas::Pose>(GetArena());
    _impl_.pose_ = reinterpret_cast<::dai::schemas::Pose*>(p);
  }
  return _impl_.pose_;
}
inline ::dai::schemas::Pose* TextPrimitive::mutable_pose() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::dai::schemas::Pose* _msg = _internal_mutable_pose();
  // @@protoc_insertion_point(field_mutable:dai.schemas.TextPrimitive.pose)
  return _msg;
}
inline void TextPrimitive::set_allocated_pose(::dai::schemas::Pose* value) {
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
  // @@protoc_insertion_point(field_set_allocated:dai.schemas.TextPrimitive.pose)
}

// bool billboard = 2;
inline void TextPrimitive::clear_billboard() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.billboard_ = false;
}
inline bool TextPrimitive::billboard() const {
  // @@protoc_insertion_point(field_get:dai.schemas.TextPrimitive.billboard)
  return _internal_billboard();
}
inline void TextPrimitive::set_billboard(bool value) {
  _internal_set_billboard(value);
  // @@protoc_insertion_point(field_set:dai.schemas.TextPrimitive.billboard)
}
inline bool TextPrimitive::_internal_billboard() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.billboard_;
}
inline void TextPrimitive::_internal_set_billboard(bool value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.billboard_ = value;
}

// double font_size = 3;
inline void TextPrimitive::clear_font_size() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.font_size_ = 0;
}
inline double TextPrimitive::font_size() const {
  // @@protoc_insertion_point(field_get:dai.schemas.TextPrimitive.font_size)
  return _internal_font_size();
}
inline void TextPrimitive::set_font_size(double value) {
  _internal_set_font_size(value);
  // @@protoc_insertion_point(field_set:dai.schemas.TextPrimitive.font_size)
}
inline double TextPrimitive::_internal_font_size() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.font_size_;
}
inline void TextPrimitive::_internal_set_font_size(double value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.font_size_ = value;
}

// bool scale_invariant = 4;
inline void TextPrimitive::clear_scale_invariant() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.scale_invariant_ = false;
}
inline bool TextPrimitive::scale_invariant() const {
  // @@protoc_insertion_point(field_get:dai.schemas.TextPrimitive.scale_invariant)
  return _internal_scale_invariant();
}
inline void TextPrimitive::set_scale_invariant(bool value) {
  _internal_set_scale_invariant(value);
  // @@protoc_insertion_point(field_set:dai.schemas.TextPrimitive.scale_invariant)
}
inline bool TextPrimitive::_internal_scale_invariant() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.scale_invariant_;
}
inline void TextPrimitive::_internal_set_scale_invariant(bool value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.scale_invariant_ = value;
}

// .dai.schemas.Color color = 5;
inline bool TextPrimitive::has_color() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.color_ != nullptr);
  return value;
}
inline const ::dai::schemas::Color& TextPrimitive::_internal_color() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  const ::dai::schemas::Color* p = _impl_.color_;
  return p != nullptr ? *p : reinterpret_cast<const ::dai::schemas::Color&>(::dai::schemas::_Color_default_instance_);
}
inline const ::dai::schemas::Color& TextPrimitive::color() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:dai.schemas.TextPrimitive.color)
  return _internal_color();
}
inline void TextPrimitive::unsafe_arena_set_allocated_color(::dai::schemas::Color* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.color_);
  }
  _impl_.color_ = reinterpret_cast<::dai::schemas::Color*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:dai.schemas.TextPrimitive.color)
}
inline ::dai::schemas::Color* TextPrimitive::release_color() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);

  _impl_._has_bits_[0] &= ~0x00000002u;
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
inline ::dai::schemas::Color* TextPrimitive::unsafe_arena_release_color() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:dai.schemas.TextPrimitive.color)

  _impl_._has_bits_[0] &= ~0x00000002u;
  ::dai::schemas::Color* temp = _impl_.color_;
  _impl_.color_ = nullptr;
  return temp;
}
inline ::dai::schemas::Color* TextPrimitive::_internal_mutable_color() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  if (_impl_.color_ == nullptr) {
    auto* p = CreateMaybeMessage<::dai::schemas::Color>(GetArena());
    _impl_.color_ = reinterpret_cast<::dai::schemas::Color*>(p);
  }
  return _impl_.color_;
}
inline ::dai::schemas::Color* TextPrimitive::mutable_color() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::dai::schemas::Color* _msg = _internal_mutable_color();
  // @@protoc_insertion_point(field_mutable:dai.schemas.TextPrimitive.color)
  return _msg;
}
inline void TextPrimitive::set_allocated_color(::dai::schemas::Color* value) {
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
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }

  _impl_.color_ = reinterpret_cast<::dai::schemas::Color*>(value);
  // @@protoc_insertion_point(field_set_allocated:dai.schemas.TextPrimitive.color)
}

// string text = 6;
inline void TextPrimitive::clear_text() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.text_.ClearToEmpty();
}
inline const std::string& TextPrimitive::text() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:dai.schemas.TextPrimitive.text)
  return _internal_text();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void TextPrimitive::set_text(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.text_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:dai.schemas.TextPrimitive.text)
}
inline std::string* TextPrimitive::mutable_text() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_text();
  // @@protoc_insertion_point(field_mutable:dai.schemas.TextPrimitive.text)
  return _s;
}
inline const std::string& TextPrimitive::_internal_text() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.text_.Get();
}
inline void TextPrimitive::_internal_set_text(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.text_.Set(value, GetArena());
}
inline std::string* TextPrimitive::_internal_mutable_text() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  return _impl_.text_.Mutable( GetArena());
}
inline std::string* TextPrimitive::release_text() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:dai.schemas.TextPrimitive.text)
  return _impl_.text_.Release();
}
inline void TextPrimitive::set_allocated_text(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.text_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.text_.IsDefault()) {
          _impl_.text_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:dai.schemas.TextPrimitive.text)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace schemas
}  // namespace dai


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_daischemas_2fTextPrimitive_2eproto_2epb_2eh
