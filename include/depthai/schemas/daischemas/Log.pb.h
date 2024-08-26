// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: daischemas/Log.proto
// Protobuf C++ Version: 4.25.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_daischemas_2fLog_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_daischemas_2fLog_2eproto_2epb_2eh

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
#include "google/protobuf/generated_enum_reflection.h"
#include "google/protobuf/unknown_field_set.h"
#include "google/protobuf/timestamp.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_daischemas_2fLog_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_daischemas_2fLog_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_daischemas_2fLog_2eproto;
namespace dai {
namespace schemas {
class Log;
struct LogDefaultTypeInternal;
extern LogDefaultTypeInternal _Log_default_instance_;
}  // namespace schemas
}  // namespace dai
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace dai {
namespace schemas {
enum Log_Level : int {
  Log_Level_UNKNOWN = 0,
  Log_Level_DEBUG = 1,
  Log_Level_INFO = 2,
  Log_Level_WARNING = 3,
  Log_Level_ERROR = 4,
  Log_Level_FATAL = 5,
  Log_Level_Log_Level_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  Log_Level_Log_Level_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool Log_Level_IsValid(int value);
extern const uint32_t Log_Level_internal_data_[];
constexpr Log_Level Log_Level_Level_MIN = static_cast<Log_Level>(0);
constexpr Log_Level Log_Level_Level_MAX = static_cast<Log_Level>(5);
constexpr int Log_Level_Level_ARRAYSIZE = 5 + 1;
const ::google::protobuf::EnumDescriptor*
Log_Level_descriptor();
template <typename T>
const std::string& Log_Level_Name(T value) {
  static_assert(std::is_same<T, Log_Level>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to Level_Name().");
  return Log_Level_Name(static_cast<Log_Level>(value));
}
template <>
inline const std::string& Log_Level_Name(Log_Level value) {
  return ::google::protobuf::internal::NameOfDenseEnum<Log_Level_descriptor,
                                                 0, 5>(
      static_cast<int>(value));
}
inline bool Log_Level_Parse(absl::string_view name, Log_Level* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Log_Level>(
      Log_Level_descriptor(), name, value);
}

// ===================================================================


// -------------------------------------------------------------------

class Log final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:dai.schemas.Log) */ {
 public:
  inline Log() : Log(nullptr) {}
  ~Log() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR Log(::google::protobuf::internal::ConstantInitialized);

  inline Log(const Log& from)
      : Log(nullptr, from) {}
  Log(Log&& from) noexcept
    : Log() {
    *this = ::std::move(from);
  }

  inline Log& operator=(const Log& from) {
    CopyFrom(from);
    return *this;
  }
  inline Log& operator=(Log&& from) noexcept {
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
  static const Log& default_instance() {
    return *internal_default_instance();
  }
  static inline const Log* internal_default_instance() {
    return reinterpret_cast<const Log*>(
               &_Log_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Log& a, Log& b) {
    a.Swap(&b);
  }
  inline void Swap(Log* other) {
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
  void UnsafeArenaSwap(Log* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Log* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Log>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Log& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const Log& from) {
    Log::MergeImpl(*this, from);
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
  void InternalSwap(Log* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "dai.schemas.Log";
  }
  protected:
  explicit Log(::google::protobuf::Arena* arena);
  Log(::google::protobuf::Arena* arena, const Log& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  using Level = Log_Level;
  static constexpr Level UNKNOWN = Log_Level_UNKNOWN;
  static constexpr Level DEBUG = Log_Level_DEBUG;
  static constexpr Level INFO = Log_Level_INFO;
  static constexpr Level WARNING = Log_Level_WARNING;
  static constexpr Level ERROR = Log_Level_ERROR;
  static constexpr Level FATAL = Log_Level_FATAL;
  static inline bool Level_IsValid(int value) {
    return Log_Level_IsValid(value);
  }
  static constexpr Level Level_MIN = Log_Level_Level_MIN;
  static constexpr Level Level_MAX = Log_Level_Level_MAX;
  static constexpr int Level_ARRAYSIZE = Log_Level_Level_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor* Level_descriptor() {
    return Log_Level_descriptor();
  }
  template <typename T>
  static inline const std::string& Level_Name(T value) {
    return Log_Level_Name(value);
  }
  static inline bool Level_Parse(absl::string_view name, Level* value) {
    return Log_Level_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kMessageFieldNumber = 3,
    kNameFieldNumber = 4,
    kFileFieldNumber = 5,
    kTimestampFieldNumber = 1,
    kLevelFieldNumber = 2,
    kLineFieldNumber = 6,
  };
  // string message = 3;
  void clear_message() ;
  const std::string& message() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_message(Arg_&& arg, Args_... args);
  std::string* mutable_message();
  PROTOBUF_NODISCARD std::string* release_message();
  void set_allocated_message(std::string* value);

  private:
  const std::string& _internal_message() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_message(
      const std::string& value);
  std::string* _internal_mutable_message();

  public:
  // string name = 4;
  void clear_name() ;
  const std::string& name() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_name(Arg_&& arg, Args_... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* value);

  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
      const std::string& value);
  std::string* _internal_mutable_name();

  public:
  // string file = 5;
  void clear_file() ;
  const std::string& file() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_file(Arg_&& arg, Args_... args);
  std::string* mutable_file();
  PROTOBUF_NODISCARD std::string* release_file();
  void set_allocated_file(std::string* value);

  private:
  const std::string& _internal_file() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_file(
      const std::string& value);
  std::string* _internal_mutable_file();

  public:
  // .google.protobuf.Timestamp timestamp = 1;
  bool has_timestamp() const;
  void clear_timestamp() ;
  const ::google::protobuf::Timestamp& timestamp() const;
  PROTOBUF_NODISCARD ::google::protobuf::Timestamp* release_timestamp();
  ::google::protobuf::Timestamp* mutable_timestamp();
  void set_allocated_timestamp(::google::protobuf::Timestamp* value);
  void unsafe_arena_set_allocated_timestamp(::google::protobuf::Timestamp* value);
  ::google::protobuf::Timestamp* unsafe_arena_release_timestamp();

  private:
  const ::google::protobuf::Timestamp& _internal_timestamp() const;
  ::google::protobuf::Timestamp* _internal_mutable_timestamp();

  public:
  // .dai.schemas.Log.Level level = 2;
  void clear_level() ;
  ::dai::schemas::Log_Level level() const;
  void set_level(::dai::schemas::Log_Level value);

  private:
  ::dai::schemas::Log_Level _internal_level() const;
  void _internal_set_level(::dai::schemas::Log_Level value);

  public:
  // fixed32 line = 6;
  void clear_line() ;
  ::uint32_t line() const;
  void set_line(::uint32_t value);

  private:
  ::uint32_t _internal_line() const;
  void _internal_set_line(::uint32_t value);

  public:
  // @@protoc_insertion_point(class_scope:dai.schemas.Log)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      3, 6, 1,
      39, 2>
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
    ::google::protobuf::internal::ArenaStringPtr message_;
    ::google::protobuf::internal::ArenaStringPtr name_;
    ::google::protobuf::internal::ArenaStringPtr file_;
    ::google::protobuf::Timestamp* timestamp_;
    int level_;
    ::uint32_t line_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_daischemas_2fLog_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Log

// .google.protobuf.Timestamp timestamp = 1;
inline bool Log::has_timestamp() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.timestamp_ != nullptr);
  return value;
}
inline const ::google::protobuf::Timestamp& Log::_internal_timestamp() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  const ::google::protobuf::Timestamp* p = _impl_.timestamp_;
  return p != nullptr ? *p : reinterpret_cast<const ::google::protobuf::Timestamp&>(::google::protobuf::_Timestamp_default_instance_);
}
inline const ::google::protobuf::Timestamp& Log::timestamp() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:dai.schemas.Log.timestamp)
  return _internal_timestamp();
}
inline void Log::unsafe_arena_set_allocated_timestamp(::google::protobuf::Timestamp* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.timestamp_);
  }
  _impl_.timestamp_ = reinterpret_cast<::google::protobuf::Timestamp*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:dai.schemas.Log.timestamp)
}
inline ::google::protobuf::Timestamp* Log::release_timestamp() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::google::protobuf::Timestamp* released = _impl_.timestamp_;
  _impl_.timestamp_ = nullptr;
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
inline ::google::protobuf::Timestamp* Log::unsafe_arena_release_timestamp() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:dai.schemas.Log.timestamp)

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::google::protobuf::Timestamp* temp = _impl_.timestamp_;
  _impl_.timestamp_ = nullptr;
  return temp;
}
inline ::google::protobuf::Timestamp* Log::_internal_mutable_timestamp() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  if (_impl_.timestamp_ == nullptr) {
    auto* p = CreateMaybeMessage<::google::protobuf::Timestamp>(GetArena());
    _impl_.timestamp_ = reinterpret_cast<::google::protobuf::Timestamp*>(p);
  }
  return _impl_.timestamp_;
}
inline ::google::protobuf::Timestamp* Log::mutable_timestamp() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::google::protobuf::Timestamp* _msg = _internal_mutable_timestamp();
  // @@protoc_insertion_point(field_mutable:dai.schemas.Log.timestamp)
  return _msg;
}
inline void Log::set_allocated_timestamp(::google::protobuf::Timestamp* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.timestamp_);
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

  _impl_.timestamp_ = reinterpret_cast<::google::protobuf::Timestamp*>(value);
  // @@protoc_insertion_point(field_set_allocated:dai.schemas.Log.timestamp)
}

// .dai.schemas.Log.Level level = 2;
inline void Log::clear_level() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.level_ = 0;
}
inline ::dai::schemas::Log_Level Log::level() const {
  // @@protoc_insertion_point(field_get:dai.schemas.Log.level)
  return _internal_level();
}
inline void Log::set_level(::dai::schemas::Log_Level value) {
  _internal_set_level(value);
  // @@protoc_insertion_point(field_set:dai.schemas.Log.level)
}
inline ::dai::schemas::Log_Level Log::_internal_level() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return static_cast<::dai::schemas::Log_Level>(_impl_.level_);
}
inline void Log::_internal_set_level(::dai::schemas::Log_Level value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.level_ = value;
}

// string message = 3;
inline void Log::clear_message() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.message_.ClearToEmpty();
}
inline const std::string& Log::message() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:dai.schemas.Log.message)
  return _internal_message();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Log::set_message(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.message_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:dai.schemas.Log.message)
}
inline std::string* Log::mutable_message() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_message();
  // @@protoc_insertion_point(field_mutable:dai.schemas.Log.message)
  return _s;
}
inline const std::string& Log::_internal_message() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.message_.Get();
}
inline void Log::_internal_set_message(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.message_.Set(value, GetArena());
}
inline std::string* Log::_internal_mutable_message() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  return _impl_.message_.Mutable( GetArena());
}
inline std::string* Log::release_message() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:dai.schemas.Log.message)
  return _impl_.message_.Release();
}
inline void Log::set_allocated_message(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.message_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.message_.IsDefault()) {
          _impl_.message_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:dai.schemas.Log.message)
}

// string name = 4;
inline void Log::clear_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.name_.ClearToEmpty();
}
inline const std::string& Log::name() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:dai.schemas.Log.name)
  return _internal_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Log::set_name(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.name_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:dai.schemas.Log.name)
}
inline std::string* Log::mutable_name() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:dai.schemas.Log.name)
  return _s;
}
inline const std::string& Log::_internal_name() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.name_.Get();
}
inline void Log::_internal_set_name(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.name_.Set(value, GetArena());
}
inline std::string* Log::_internal_mutable_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  return _impl_.name_.Mutable( GetArena());
}
inline std::string* Log::release_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:dai.schemas.Log.name)
  return _impl_.name_.Release();
}
inline void Log::set_allocated_name(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.name_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.name_.IsDefault()) {
          _impl_.name_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:dai.schemas.Log.name)
}

// string file = 5;
inline void Log::clear_file() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.file_.ClearToEmpty();
}
inline const std::string& Log::file() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:dai.schemas.Log.file)
  return _internal_file();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Log::set_file(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.file_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:dai.schemas.Log.file)
}
inline std::string* Log::mutable_file() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_file();
  // @@protoc_insertion_point(field_mutable:dai.schemas.Log.file)
  return _s;
}
inline const std::string& Log::_internal_file() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.file_.Get();
}
inline void Log::_internal_set_file(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.file_.Set(value, GetArena());
}
inline std::string* Log::_internal_mutable_file() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  return _impl_.file_.Mutable( GetArena());
}
inline std::string* Log::release_file() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:dai.schemas.Log.file)
  return _impl_.file_.Release();
}
inline void Log::set_allocated_file(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.file_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.file_.IsDefault()) {
          _impl_.file_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:dai.schemas.Log.file)
}

// fixed32 line = 6;
inline void Log::clear_line() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.line_ = 0u;
}
inline ::uint32_t Log::line() const {
  // @@protoc_insertion_point(field_get:dai.schemas.Log.line)
  return _internal_line();
}
inline void Log::set_line(::uint32_t value) {
  _internal_set_line(value);
  // @@protoc_insertion_point(field_set:dai.schemas.Log.line)
}
inline ::uint32_t Log::_internal_line() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.line_;
}
inline void Log::_internal_set_line(::uint32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.line_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace schemas
}  // namespace dai


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::dai::schemas::Log_Level> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::dai::schemas::Log_Level>() {
  return ::dai::schemas::Log_Level_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_daischemas_2fLog_2eproto_2epb_2eh
